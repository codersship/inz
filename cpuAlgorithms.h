/*
 * cpuAlgorithms.h
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#ifndef CPUALGORITHMS
#define CPUALGORITHMS

#include "point.h"
#include "functions.h"

typedef struct parameters	// parametry watku
{
	Function* f;
	Point* points;
	Point result;
	int it;
} Parameters;

class CPUAlgorithms {
private:
	static void* neldermead_thread(void* param);

public:
	CPUAlgorithms();
	~CPUAlgorithms();

	static Point neldermead(Point *tab, Function* f);

	friend class CPUAgorithmsTest;
};

#endif /* CPUALGORITHMS */
