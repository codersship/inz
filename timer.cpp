/*
 * timer.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: statek
 */

#include"timer.h"

Timer::Timer() {
	state = 'n';	//NEW
}

Timer::Timer(bool startsAtStart) {
	Timer();
	if (startsAtStart == true)
		start();
}

Timer::~Timer() {
}

void Timer::start() throw (TimerException) {
	if (state == 'm') {
		throw new TimerException(WRONG_STATE);
	}
	state = 'm';	//MEASURING
	gettimeofday(&start_t, NULL);
}

void Timer::stop() throw (TimerException) {
	if (state != 'm') {
		throw new TimerException(WRONG_STATE);
	}
	state = 's';	//STOPPED
	gettimeofday(&end_t, NULL);
}

double Timer::delta() throw (TimerException) {
	if (state != 's') {
		throw new TimerException(WRONG_STATE);
	}
	return (end_t.tv_sec - start_t.tv_sec) + (double) (end_t.tv_usec - start_t.tv_usec) / 1000000;
}
