/*
 * main_test.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: statek
 */

#include <cppunit/TestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/ui/text/TextTestRunner.h>
//#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "const.h"
#include "cpuAlgorithms_test.cpp"
#include "cpuAlgorithms.h"
#include "debug.h"
#include "functions_test.cpp"
#include "nelderMead_test.cpp"
#include "nelderMead.h"
#include "point_test.cpp"
#include "point.h"
#include "timer_test.cpp"

int Point::counter = 0;

int NelderMead::contractions = 0;
int NelderMead::expansions = 0;
int NelderMead::reductions = 0;

std::string NelderMead::logFileName = "NelderMead.log";
std::string CPUAlgorithms::logFileName = "cpuAlg.log";

int main() {
	srand (time(NULL));

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

	return 1;
}


