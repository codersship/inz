/*
 * nelderMead.h
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#ifndef NELDERMEAD
#define NELDERMEAD

#include<cmath>

#include"const.h"
#include"functions.h"
#include"point.h"

class nmParams {
public:
	double alpha;
	double beta;
	double gamma;
	double epsilon;
	nmParams();
	~nmParams();
};

class nmIndexes {
public:
	int x1;
	int xn;
	int xn1;

	nmIndexes();
	~nmIndexes();
};

enum Direction {
	MIN, MAX
};

class NelderMead {
private:
	int dim;
	nmParams params;
	Direction dir;
	Point *points;
	Point center, xr, xe, result;
	nmIndexes idx;
	Function* fun;
	int it;

	void init();
	void calculateIndexes();
	void calculateCenter();
	void reflection();
	void expansion();
	void contraction();
	void reduction();
	bool stop();

	bool isBetter(Point b, Point w);

public:

	static int expansions;
	static int contractions;
	static int reductions;

	NelderMead();
	NelderMead(Function* f);
	~NelderMead();
	void run();

	Point getResult();
	int getIterations();
	void setPoints(Point* p);

	friend class NelderMeadTest;
};

#endif /* NELDERMEAD */
