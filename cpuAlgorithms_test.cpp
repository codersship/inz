/*
 * cpuAlgorithms_test.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#include "cpuAlgorithms.h"

#include<cppunit/TestFixture.h>
#include<cppunit/Test.h>
#include<cppunit/TestAssert.h>
#include<cppunit/TestCaller.h>
#include<cppunit/TestSuite.h>

using namespace CppUnit;

class CPUAgorithmsTest: public CppUnit::TestFixture {
public:
//TODO napisac testy
	static Test* suite() {
		TestSuite* testsSuite = new TestSuite("CPUAgorithmsTest");
//		testsSuite->addTest(new TestCaller<NelderMeadTest>("testCreation", &CPUAgorithmsTest::creationTest));
//		testsSuite->addTest(new TestCaller<NelderMeadTest>("testAddition", &CPUAgorithmsTest::measureTest));
//		testsSuite->addTest(new TestCaller<NelderMeadTest>("testOddition", &CPUAgorithmsTest::statesTest));

		return testsSuite;
	}
};
