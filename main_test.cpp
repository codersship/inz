/*
 * main_test.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: statek
 */

#include<cppunit/ui/text/TestRunner.h>
#include<iostream>

#include"const.h"
#include"cpuAlgorithms_test.cpp"
#include"functions_test.cpp"
#include"nelderMead_test.cpp"
#include"point_test.cpp"
#include"timer_test.cpp"
#include"debug.h"

int Point::counter = 0;

int NelderMead::contractions = 0;
int NelderMead::expansions = 0;
int NelderMead::reductions = 0;

int main() {
	Debug debug;
	debug.log("Debug test.");
/*
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TimerTest::suite());			// 3 tests
	runner.addTest(FunctionsTest::suite());		//
	runner.addTest(NelderMeadTest::suite());	// 1
	runner.addTest(CPUAgorithmsTest::suite()); //
	runner.addTest(PointTest::suite());			// 8

	runner.run();
	std::cout << "Point::counter = " << Point::counter << std::endl;

	std::cout << "NelderMead::contractions = " << NelderMead::contractions << std::endl;
	std::cout << "NelderMead::expansions = " << NelderMead::expansions << std::endl;
	std::cout << "NelderMead::reductions = " << NelderMead::reductions << std::endl;
*/
	return 1;
}

