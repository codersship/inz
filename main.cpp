/*
 * main.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: statek
 */

#include<stdlib.h>

#include"const.h"
#include"nelderMead.h"
#include"point.h"
#include"timer.h"
#include"cpuAlgorithms.h"
#include"debug.h"

int Point::counter = 0;

int NelderMead::contractions = 0;
int NelderMead::expansions = 0;
int NelderMead::reductions = 0;

int main(int argc, char **argv) {
	Function* fun = new SimpleQuadFunction();
	Timer cpuTimer, gpuTimer;
	Point tab[(fun->dim+1)*SIZE];
	Point cpuOpt, gpuOpt;
	srand (time(NULL));
	for (int i=0;i<(fun->dim+1)*SIZE;++i)
		tab[i].randomizeCoordinates();
	cpuTimer.start();
		cpuOpt = CPUAlgorithms::neldermead(tab,fun);
	cpuTimer.stop();
	std::cout<<"cpu Optimum: "<<cpuOpt<<"cpu Time: "<<cpuTimer.delta()<<std::endl;
	gpuTimer.start();
		//gpuOpt=gpuTest(tab);
	gpuTimer.stop();
	std::cout<<"gpu Optimum: "<<cpuOpt<<"gpu Time: "<<gpuTimer.delta()<<std::endl;
	return 0;
}

/*					impl	exce	test
 * 	cpuAlgoithms	-		?		-
 *  functions		+?		+		+?
 *	main			+		+		+
 *	main_test		+		+		+
 *	NelderMead		+		+		-
 *	point			+		+		+
 *	timer			+		-		-
 */

