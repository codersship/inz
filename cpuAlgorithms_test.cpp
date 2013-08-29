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

	void exceptionTest()
	{

	}

	static Test* suite() {
		TestSuite* testsSuite = new TestSuite("CPUAgorithmsTest");
		testsSuite->addTest(new TestCaller<NelderMeadTest>("testExceptions", &CPUAgorithmsTest::exceptionsTest));

		return testsSuite;
	}
};
