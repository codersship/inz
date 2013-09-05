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
#include"parser.h"

int Point::counter = 0;

int NelderMead::contractions = 0;
int NelderMead::expansions = 0;
int NelderMead::reductions = 0;

int CPUAlgorithms::threadCounter = 0;

std::string NelderMead::logFileName = "NelderMead.log";
std::string CPUAlgorithms::logFileName = "cpuAlg.log";

int main(int argc, char **argv) {
//	Timer timer;
//	timer.start();
//	sleep(70);
//	timer.stop();
//	std::cout<< timer.delta()<<std::endl<<timer.deltaToString();
//	return 0;

	//Parser(argc, argv);
	//TODO parse parameters
	Function* fun = new SimpleQuadFunction();
	Timer cpuTimer, gpuTimer;
	Point tab[(fun->dim+1)*SIZE];
	Point cpuOpt, gpuOpt;
	srand (1);
	for (int i=0;i<(fun->dim+1)*SIZE;++i)
	{
		Point tmp(fun->dim);
		tmp.randomizeCoordinates();
		tab[i]=tmp;
	}
	cpuTimer.start();
		cpuOpt = CPUAlgorithms::neldermead(tab,fun);
	cpuTimer.stop();
	gpuTimer.start();
		//gpuOpt=GPUAlgorithms::neldermead(tab,fun);
	gpuTimer.stop();
	std::cout<<"Function optimum: "<<*fun->optimum;
	std::cout<<"CPU      optimum: "<<cpuOpt<<"cpu Time: "<<cpuTimer.deltaToString()<<std::endl;
	std::cout<<"GPU      optimum: "<<cpuOpt<<"gpu Time: "<<gpuTimer.delta()<<std::endl;
	return 0;
}

/*					impl	exce	test
 * 	cpuAlgorithms	-		?		-
 * 	gpuAlgorithms	-		-		-
 *  functions		+?		+		+
 *	main			+		+		+
 *	main_test		+		+		+
 *	NelderMead		+		+		+
 *	point			+		+		+
 *	timer			+		+		+
 *	debug			+?		+		+
 *	parser			+?		-		-
 */

