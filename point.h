/*
 * point.h
 *
 *  Created on: Aug 15, 2013
 *      Author: statek
 */

#ifndef POINT
#define POINT

#include<iostream>
#include<stdexcept>

#include"const.h"

class Point {

private:
	double* coord;
	int dim;

	void init();
public:
	static int counter;

public:
	Point();
	Point(const Point& p);
	Point(int dimention);
	~Point();

	double getCrd(const int d) const throw (std::invalid_argument);
	void setCrd(const int d, const double crd) throw (std::invalid_argument);
	void setCrds(const double *crds);
	void loadFromUser();
	void randomizeCoordinates();

	friend std::ostream & operator<<(std::ostream &ret, const Point &p);
	Point operator+(const Point p);
	Point operator-(const Point p);
	Point operator*(double d);
	Point operator*(int d);
	Point operator/(double d) throw (std::invalid_argument);
	Point operator/(int d) throw (std::invalid_argument);
	Point& operator=(const Point& p);
	bool operator==(const Point& p);

friend class PointTest;
};

#endif /* POINT */
