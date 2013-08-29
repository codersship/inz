/*
 * functions.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#include "functions.h"

Function1::Function1() {
	dim = 3;
	double opt[] = {1, 2, 3};
	optimum.setCrds(opt);
}
double Function1::calc(const Point& p) {
	return (p.getCrd(0)-1)*(p.getCrd(0)-1)+(p.getCrd(1)-2)*(p.getCrd(1)-2)+(p.getCrd(2)-3)*(p.getCrd(2)-3);
}
double Function1::operator ()(const Point& p) {
	return (p.getCrd(0)-1)*(p.getCrd(0)-1)+(p.getCrd(1)-2)*(p.getCrd(1)-2)+(p.getCrd(2)-3)*(p.getCrd(2)-3);
}

RosenbrocksFunction::RosenbrocksFunction() {
	dim = 2;
	double opt[] = {1, 1};
	optimum.setCrds(opt);
}

double RosenbrocksFunction::operator ()(const Point& p) {
	return (1-p.getCrd(0))*(1-p.getCrd(0)) + 100*(p.getCrd(1)-p.getCrd(0)*p.getCrd(0))*(p.getCrd(1)-p.getCrd(0)*p.getCrd(0));
}

double RosenbrocksFunction::calc(const Point& p) {
	return (1-p.getCrd(0))*(1-p.getCrd(0)) + 100*(p.getCrd(1)-p.getCrd(0)*p.getCrd(0))*(p.getCrd(1)-p.getCrd(0)*p.getCrd(0));
}

SimpleQuadFunction::SimpleQuadFunction() {
	dim = 2;
	double opt[] = {0, 0};
	optimum.setCrds(opt);
}

double SimpleQuadFunction::operator ()(const Point& p) {
	return calc(p);
}

double SimpleQuadFunction::calc(const Point& p) {
	return p.getCrd(0)*p.getCrd(0) + p.getCrd(1)*p.getCrd(1);
}
