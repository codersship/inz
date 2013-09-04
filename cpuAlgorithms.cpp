/*
 * cpuAlgorithms.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#include "cpuAlgorithms.h"
#include "nelderMead.h"
#include <sstream>

CPUAlgorithms::CPUAlgorithms() {
}

CPUAlgorithms::~CPUAlgorithms() {
}

void* CPUAlgorithms::neldermead_thread(void* params) {
	Debug* debug = new Debug(logFileName);
	nmThreadParameters* param = (nmThreadParameters*) params;
	//Point** points;// = new Point*[param->f->dim + 1];
	NelderMead nm(param->f);
	debug->ss << "THREAD " << param->thread_num << ": Start points: " << param->points[0].toString() << " " << param->points[1].toString() << " " << param->points[2].toString();
	debug->log();
	//for (int d = 0; d < param->f->dim + 1; ++d)
	//	*points[d] = param->points[d];
	nm.setPoints(&param->points);
	nm.run();
	param->result = nm.getResult();
	param->it = nm.getIterations();
	debug->ss << "THREAD " << param->thread_num << ": Optimum result: " << param->result.toString();
	debug->log();
	delete debug;
	return 0;
}

Point CPUAlgorithms::neldermead(Point* tab, Function* f) {
	Debug* debug = new Debug(logFileName);
	std::stringstream ss;
	Point result[SIZE];
	pthread_t* threads[SIZE];
	nmThreadParameters* param[SIZE];
	for (int t = 0; t < SIZE; ++t) {
		param[t] = new nmThreadParameters;	//(Parameters*) malloc(sizeof(Parameters));
		threads[t] = new pthread_t;			//(pthread_t*) malloc(sizeof(pthread_t));
	}

	for (int t = 0; t < SIZE; ++t) {
		param[t]->points = &tab[3 * t];
		param[t]->f = f;
		debug->ss << "URUCHAMIAM WATEK " << t;
		debug->log();

		pthread_create(threads[t], NULL, &neldermead_thread, (void*) param[t]);
	}
	for (int t = 0; t < SIZE; ++t) {
		pthread_join(*threads[t], NULL);
		result[t] = param[t]->result;
		debug->ss << "ZAKONCZYLEM WATEK " << t << "\n\tL. it= " << param[t]->it << "\n\tWynik= " << result[t];
		debug->log();
	}
	Point opt;
	for (int i = 0; i < SIZE; ++i)
		opt = opt + result[i];
	opt = opt / SIZE;
	for (int t = 0; t < SIZE; ++t) {
		delete param[t];
		delete threads[t];
	}
	delete debug;
	return opt;
}
