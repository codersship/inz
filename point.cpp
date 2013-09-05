/*
 * point.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: statek
 */

#include"point.h"

#include<cstdlib>
#include<ctime>
#include<stdexcept>
#include<sstream>

Point::Point() {
	init(0);
	++counter;
}

Point::Point(const Point& p) {
	init(p.dim);
	for (int i = 0; i < p.dim; ++i)
		coord[i] = p.getCrd(i);
	++counter;
}

Point::Point(int dimention) {
	init(dimention);
	++counter;
}

Point::~Point() {
	delete[] coord;
	--counter;
}

double Point::getCrd(const int d) const throw (std::invalid_argument) {
	if (coord == 0) {
		throw std::invalid_argument("Coordinates don't exist.");
	}
	if (d > dim) {
		throw std::invalid_argument("That coordinate doesn't exist.(get)");
	}
	return coord[d];
}

void Point::setCrd(const int d, const double crd) throw (std::invalid_argument) {
	if (d < dim) {
		coord[d] = crd;
	} else {
		throw std::invalid_argument("That coordinate doesn't exist.(set)");
	}
}

void Point::setCrds(const double *crds) {
	for (int i = 0; i < dim; ++i) {
		coord[i] = *(crds + i);
	}
}

void Point::randomizeCoordinates() {
	double x;
	for (int i = 0; i < dim; ++i) {
		x = (rand() % 20000) / 100 - 100;
		setCrd(i, x);
	}
}

std::ostream & operator<<(std::ostream &ret, const Point &p) {
	int i = 0;
	ret << "[ ";
	for (int i = 0; i < p.dim - 1; ++i)
		ret << p.getCrd(i) << " , ";
	ret << p.getCrd(i + 1) << " ]" << std::endl;
	return ret;
}
std::string Point::toString() {
	std::stringstream ss;
	std::string str;
	int i = 0;
	ss << "[";
	for (int i = 0; i < dim - 1; ++i) {
		ss << getCrd(i);
		ss << ",";
	}
	ss << getCrd(i + 1);
	ss << "]\n";
	ss >> str;
	return str;
}

Point Point::operator+(const Point p) {
	Point tmp(dim);
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, getCrd(i) + p.getCrd(i));
	return tmp;
}

Point Point::operator-(const Point p) {
	Point tmp(dim);
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, this->getCrd(i) - p.getCrd(i));
	return tmp;
}

Point Point::operator*(double d) {
	Point tmp(dim);
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, getCrd(i) * d);
	return tmp;
}

Point Point::operator/(double d) throw (std::invalid_argument) {
	if (d == 0.0)
		throw std::invalid_argument("Don't divide by zero.");
	Point tmp(dim);
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, getCrd(i) / d);
	return tmp;
}
;
Point Point::operator*(int d) {
	Point tmp(dim);
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, getCrd(i) * (double) d);
	return tmp;
}

Point Point::operator/(int d) throw (std::invalid_argument) {
	if (d == 0)
		throw std::invalid_argument("Don't divide by zero.");
	Point tmp(dim);
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, getCrd(i) / (double) d);
	return tmp;
}

Point& Point::operator=(const Point& p) {
	if (this == &p)
		return *this;
	if (coord != 0) delete[] coord;
	init(p.dim);
	for (int i = 0; i < dim; ++i)
		setCrd(i, p.getCrd(i));
	return *this;
}

void Point::init(int dimention) {
	dim = dimention;
	coord = new double[dim];
	for (int i = 0; i < dim; ++i)
		coord[i] = 0;
}

bool Point::operator==(const Point& p) {
	bool result = true;
	for (int i = 0; i < dim; ++i) {
		if (getCrd(i) != p.getCrd(i))
			result = false;
	}
	return result;
}
