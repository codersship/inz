/*
 * functions.h
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#ifndef FUNCTIONS
#define FUNCTIONS

#include<string>

#include"point.h"

class Function {
public:
	int dim;
	Point optimum;
	virtual ~Function(){};
	virtual double operator()(const Point& p){return 0;};
	virtual double calc(const Point& p){return 0;};
	virtual Point getOptimum(){return optimum;};
};

class Function1 : public Function
{
public:
	Function1();
	~Function1(){};
	double operator()(const Point& p);
	double calc(const Point& p);
};	// optimum [1 2 3]

class RosenbrocksFunction : public Function
{
public:
	RosenbrocksFunction();
	~RosenbrocksFunction(){};
	double operator()(const Point& p);
	double calc(const Point& p);
};	// optimum [1 1]

class SimpleQuadFunction : public Function
{
public:
	SimpleQuadFunction();
	~SimpleQuadFunction(){};
	double operator()(const Point& p);
	double calc(const Point& p);
};	// optimum [0 0]

#endif /* FUNCTIONS */
