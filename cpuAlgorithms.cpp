/*
 * cpuAlgorithms.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#include "cpuAlgorithms.h"
#include "nelderMead.h"


CPUAlgorithms::CPUAlgorithms() {
}

CPUAlgorithms::~CPUAlgorithms() {
}

void* CPUAlgorithms::neldermead_thread(void* params) {
	Debug* debug = new Debug(logFileName);
	nmThreadParameters* param=(nmThreadParameters*) params;
	Point** points = new Point*[param->f->dim+1];//(param->f->dim);
	for (int i=0; i< param->f->dim+1; ++i)
	{
		points[i] = new Point(param->f->dim);
		points[i]->randomizeCoordinates();
	}
	NelderMead nm(param->f);
	//debug->log("THREAD "+param->thread_num+": Start points: "+param->points[0].toString()+" "+param->points[1].toString()+" "+param->points[2].toString());
	for (int d=0; d<param->f->dim+1; ++d)
		*points[d] = param->points[d];
	nm.setPoints(points);
	nm.run();
	param->result=nm.getResult();
	param->it=nm.getIterations();
	//debug->log("THREAD "+param->thread_num+": Optimum result: "+param->result.toString());
	delete debug;
	return 0;
}

Point CPUAlgorithms::neldermead(Point* tab, Function* f) {
	Debug* debug = new Debug(logFileName);
	Point result[SIZE];
	pthread_t* threads[SIZE];
	nmThreadParameters* param[SIZE];
	for (int t=0;t<SIZE;++t)
	{
		param[t]=new nmThreadParameters;	//(Parameters*) malloc(sizeof(Parameters));
		threads[t]=new pthread_t;			//(pthread_t*) malloc(sizeof(pthread_t));
	}

	for (int t=0;t<SIZE;++t)
	{
		param[t]->points=&tab[3*t];
		std::cout<<"URUCHAMIAM WATEK "<<t<<std::endl;
		pthread_create(threads[t], NULL, &neldermead_thread, (void*) param[t]);
	}
	for (int t=0;t<SIZE;++t)
	{
		pthread_join(*threads[t], NULL);
		result[t]=param[t]->result;
		std::cout<<"ZAKONCZYLEM WATEK "<<t<<std::endl;
		std::cout<<"\tL. it= "<<param[t]->it<<std::endl;
		std::cout<<"\tWynik= "<<result[t]<<std::endl;
	}
	Point opt;
	for (int i=0;i<SIZE;++i)
		opt=opt+result[i];
	opt=opt/SIZE;
	for (int t=0;t<SIZE;++t)
	{
		delete param[t];
		delete threads[t];
	}
	delete debug;
	return opt;
}
