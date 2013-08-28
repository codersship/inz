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

Point::Point() {
	init();
}

Point::Point(const Point& p) {
	init();
	for (int i = 0; i < dim; ++i)
		coord[i] = p.getCrd(i);
}

Point::Point(int dimention) {
	init();
	dim = dimention;
}

Point::~Point() {
	delete[] coord;
	--counter;
}

double Point::getCrd(const int d) const throw(std::invalid_argument) {
	if (d > dim) {
		throw std::invalid_argument("That coordinate doesn't exist.");
	}
	if (coord == 0) {
		throw std::invalid_argument("Coordinates don't exist.");
	}
	return coord[d];
}

void Point::setCrd(const int d, const double crd) throw (std::invalid_argument) {
	if (d < dim) {
		coord[d] = crd;
	} else {
		throw std::invalid_argument("That coordinate doesn't exist.");
	}
}

void Point::setCrds(const double *crds) {
	for (int i=0; i<dim; ++i)
	{
		coord[i]=*(crds+i);
	}
}

void Point::loadFromUser() {
	double x;
	int i;
	std::cout << "[ " << std::endl;
	for (i = 0; i < dim - 1; ++i) {
		std::cin >> x;
		setCrd(i, x);
	}
	std::cin >> x;
	setCrd(i, x);
	std::cout << "]" << std::endl;
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
Point Point::operator+(const Point p) {
	Point tmp;
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, getCrd(i) + p.getCrd(i));
	return tmp;
}
;
Point Point::operator-(const Point p) {
	Point tmp;
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, this->getCrd(i) - p.getCrd(i));
	return tmp;
}
;
Point Point::operator*(double d) {
	Point tmp;
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, getCrd(i) * d);
	return tmp;
}
;
Point Point::operator/(double d) throw (std::invalid_argument) {
	if (d == 0.0)
		throw new std::invalid_argument("Don't divide by zero.");
	Point tmp;
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, getCrd(i) / d);
	return tmp;
}
;
Point Point::operator*(int d) {
	Point tmp;
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, getCrd(i) * (double) d);
	return tmp;
}
;
Point Point::operator/(int d) throw (std::invalid_argument) {
	if (d == 0)
		throw new std::invalid_argument("Don't divide by zero.");
	Point tmp;
	for (int i = 0; i < dim; ++i)
		tmp.setCrd(i, getCrd(i) / (double) d);
	return tmp;
}
;
Point& Point::operator=(const Point& p) {
	if (this == &p)
		return *this;
	for (int i = 0; i < dim; ++i)
		setCrd(i, p.getCrd(i));
	return *this;
}
;

void Point::init() {
	dim = DIM;
	coord = new double[dim];
	for (int i = 0; i < dim; ++i)
		coord[i] = 0;
	++counter;
}

bool Point::operator==(const Point& p) {
	bool result = true;
	for (int i = 0; i < dim; ++i) {
		if (getCrd(i) != p.getCrd(i))
			result = false;
	}
	return result;
}
