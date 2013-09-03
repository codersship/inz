/*
 * cpuAlgorithms.h
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#ifndef CPUALGORITHMS
#define CPUALGORITHMS

#include"point.h"
#include"functions.h"
#include"debug.h"

typedef struct parameters	// parametry watku dla alg Neldera-Meada
{
	Function* f;
	Point* points;
	Point result;
	int it;
	int thread_num;
} nmThreadParameters;

class CPUAlgorithms {
private:
	static void* neldermead_thread(void* params);

public:
	static std::string logFileName;

	CPUAlgorithms();
	~CPUAlgorithms();

	static Point neldermead(Point *tab, Function* f);

	friend class CPUAgorithmsTest;
};

#endif /* CPUALGORITHMS */
