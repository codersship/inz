/*
 * nelderMead.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#include "nelderMead.h"

#include<sstream>

NelderMead::NelderMead(Function* f) {
	init(f->dim);
	fun = f;
}
NelderMead::NelderMead() {
	init(0);
}

NelderMead::~NelderMead() {
	delete debug;
}

void NelderMead::calculateIndexes() {
	debug->log("\"sorting points\".");
	idx.x1 = 0;
	idx.xn = 0;
	idx.xn1 = 0;
	for (int j = 1; j < dim + 1; ++j) {
		if (isBetter(*points[j],*points[idx.x1]))
			idx.x1 = j;
		if (isBetter(*points[idx.xn1],*points[j])) {
			idx.xn = idx.xn1;
			idx.xn1 = j;
		} else if (isBetter(*points[idx.xn],*points[j]))
			idx.xn = j;
	};

}

void NelderMead::calculateCenter() {
	debug->log("calculation of center point.");
	Point c(dim);
	for (int j = 0; j < dim + 1; ++j) {
		if (j != idx.xn1)
			c = c + *points[j];
	}
	center = c / dim;
}

bool NelderMead::stop() {
	for (int p1 = 0; p1 < dim + 1; ++p1)
		for (int p2 = p1 + 1; p2 < dim + 1; ++p2)
			for (int crd = 0; crd < dim; ++crd) {
				if (std::abs(points[p1]->getCrd(crd) -points[p2]->getCrd(crd)) > EPSILON)
					return false;
			}
	return true;
}

void NelderMead::init(int dimention) {
	debug = new Debug(logFileName);
	debug->log("initiation of NM.");
	dim = dimention;
	it = 0;
	dir = MIN;
	points = 0;
}

void NelderMead::run() {
	debug->log("NM algorithm starts.");
	it = 0;
	//while (!stop()) {
		std::stringstream ss;
		ss<< "Iteration " << ++it << "\n points:\t";
		for (int i=0; i<dim+1; ++i)
			ss<<points[i]->toString() <<"\t";
		debug->log( ss.str() );
		calculateIndexes();
		result = *points[idx.x1];
		calculateCenter();
		reflection();
		if (isBetter(xr, *points[idx.x1])) {
			expansion();
			//continue;
		}
		if (isBetter(*points[idx.xn], xr)) {
			contraction();
		//	continue;
		}
		reduction();
	//}
}

Point NelderMead::getResult() {
	return result;
}

int NelderMead::getIterations() {
	return it;
}

void NelderMead::setPoints(Point** newPoints) {
	points = newPoints;
}

nmParams::nmParams() {
	alpha = ALPHA;
	beta = BETA;
	gamma = GAMMA;
	epsilon = EPSILON;
}

nmParams::~nmParams() {
}

nmIndexes::nmIndexes() {
	x1 = 0;
	xn = 0;
	xn1 = 0;
}

nmIndexes::~nmIndexes() {
}

void NelderMead::reflection() {
	xr = center + (center - *points[idx.xn1]) * params.alpha;
	std::string str = "REFLECTION. xr =";
	debug->log( str += xr.toString());
}

void NelderMead::expansion() {
	++expansions;
	xe = center + (xr - center) * params.beta;
	if (isBetter(xe, xr))
		*points[idx.xn1] = xe;
	else
		*points[idx.xn1] = xr;
	std::string str = "EXPANSION. xe =";
	debug->log( str += xe.toString());
}

void NelderMead::contraction() {

	++contractions;
	while (true) {
		if (isBetter(xr, *points[idx.xn1]))
			xe = center + (*points[idx.xn1] - center) * params.gamma;
		else
			xe = center + (xr - center) * params.gamma;
		//if (isBetter(xe, *points[idx.xn1]) && isBetter(xe, xr)) {
			*points[idx.xn1] = xe;
			std::string str = "CONTRACTION. xe =";
			debug->log( str += xe.toString());
			return;
		//}  TODO how explain it?
	}
}

void NelderMead::reduction() {
	debug->log("REDUCTION.");
	++reductions;
	*points[idx.xn1] = xr;
}

bool NelderMead::isBetter(Point b, Point w) {
	bool result = fun->calc(b) > fun->calc(w);
	if (dir == MIN)
		result = !result;
	return result;
}
