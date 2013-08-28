/*
 * timer.h
 *
 *  Created on: Aug 15, 2013
 *      Author: statek
 */

#ifndef TIMER
#define TIMER

#include<exception>
#include<string>
#include<sys/time.h>
#include<unistd.h>

enum TimerExceptionMsg {
	WRONG_STATE
};

class TimerException: public std::exception {
public:

private:
	TimerExceptionMsg msg;
	std::string getCommunicate() {
		std::string result = "Unrecognized exception.";
		switch (msg)
		{
		case WRONG_STATE :
			result = "Wrong operation for this state.";
		};
		return result;
	}
public:
	TimerException(TimerExceptionMsg newExMsg) {
		msg = newExMsg;
	}
	std::string getMsg() {
		return getCommunicate();
	}
};

class Timer {
private:
	struct timeval start_t, end_t;
	char state;
public:
	Timer();
	Timer(bool s);	//konstruktor
	~Timer();	    //destruktor
	void start() throw(TimerException);	//funkcja rozpoczynajaca odmierzanie
	void stop() throw(TimerException);	//funkcja konczoaca odmierzanie
	double delta() throw(TimerException);	//funkcja zwracajaca roznice czasow
	friend class TimerTest;
};
#endif /* TIMER */
