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
	debug->ss <<"\"sorting\" points.";
	debug->log();
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
	debug->ss <<"calculation of center point.";
	debug->log();
	Point c(dim);
	for (int j = 0; j < dim + 1; ++j) {
		if (j != idx.xn1)
			c = c + *points[j];
	}
	center = c / dim;
}

bool NelderMead::stop() {
	if (it>MAXIT) return true;
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
	debug->ss<<"initiation of NM.";
	debug->log();
	dim = dimention;
	it = 0;
	dir = MIN;
	points = 0;
}

void NelderMead::run() {
	debug->ss <<"NM algorithm starts.";
	debug->log();
	it = 0;
	while (!stop()) {
		debug->ss<< "Iteration " << ++it << "\n points:\t";
		for (int i=0; i<dim+1; ++i)
			debug->ss<<points[i]->toString() <<"\t";
		debug->log();
		calculateIndexes();
		result = *points[idx.x1];
		calculateCenter();
		reflection();
		if (isBetter(xr, *points[idx.x1])) {
			expansion();
			continue;
		}
		if (isBetter(*points[idx.xn], xr)) {
			contraction();
			continue;
		}
		reduction();
	}
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
	debug->ss<< "REFLECTION. xr =" <<xr;
	debug->log();
}

void NelderMead::expansion() {
	++expansions;
	xe = center + (xr - center) * params.beta;
	if (isBetter(xe, xr))
		*points[idx.xn1] = xe;
	else
		*points[idx.xn1] = xr;
	debug->ss<< "EXPANSION. xe ="<<xe;;
	debug->log();
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
			debug->ss << "CONTRACTION. xe =" << xe;
			debug->log();
			return;
		//} // TODO how explain it?
	}
}

void NelderMead::reduction() {
	debug->ss <<"REDUCTION.";
	debug->log();
	++reductions;
	*points[idx.xn1] = xr;
}

bool NelderMead::isBetter(Point b, Point w) {
	bool result = fun->calc(b) > fun->calc(w);
	if (dir == MIN)
		result = !result;
	return result;
}
