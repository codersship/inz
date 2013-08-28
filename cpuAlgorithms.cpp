/*
 * cpuAlgorithms.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#include "cpuAlgorithms.h"

CPUAlgorithms::CPUAlgorithms() {
}

CPUAlgorithms::~CPUAlgorithms() {
}

static void* CPUAlgorithms::neldermead_thread(void* params) {
//	Parameters* param=(Parameters*) params;
//	Point points[3];
//	NelderMead* nm;
//	nm = new NelderMead();
//	/*if (DEBUG_MODE)
//		std::cout<<"Punkty startowe: "<<std::endl
//		<<param->points[0]<<param->points[1]<<param->points[2];*/
//	for (int d=0; d<DIM; ++d)
//		points[d]=param->points[d];
//	nm->run();
//	param->result=nm->getResult();
//	param->it=nm->getIterations();
//	delete nm;
//	//if (DEBUG_MODE)
//	//	std::cout<<"otrzymalem wynik: "<<param->result<<std::endl;
	return 0;
}

static Point CPUAlgorithms::neldermead(Point* tab, Function* f) {
//	Point result[SIZE];
//	pthread_t* threads[SIZE];
//	Parameters* param[SIZE];
//	for (int t=0;t<SIZE;++t)
//	{
//		param[t]=new Parameters;//(Parameters*) malloc(sizeof(Parameters));
//		threads[t]=new pthread_t;//(pthread_t*) malloc(sizeof(pthread_t));
//	}
//
//	for (int t=0;t<SIZE;++t)
//	{
//		param[t]->points=&tab[3*t];
//		std::cout<<"URUCHAMIAM WATEK "<<t<<std::endl;
//		pthread_create(threads[t], NULL, &nm_thread, (void*) param[t]);
//	}
//	for (int t=0;t<SIZE;++t)
//	{
//		pthread_join(*threads[t], NULL);
//		result[t]=param[t]->result;
//		std::cout<<"ZAKONCZYLEM WATEK "<<t<<std::endl;
//		std::cout<<"\tL. it= "<<param[t]->it<<std::endl;
//		std::cout<<"\tWynik= "<<result[t]<<std::endl;
//
//	}
//	Point opt;
//	for (int i=0;i<SIZE;++i)
//		opt=opt+result[i];
//	opt=opt/SIZE;
//	for (int t=0;t<THREAD_NUM;++t)
//	{
//		delete param[t];
//		delete threads[t];
//	}
//	return opt;
	return 0;
}
