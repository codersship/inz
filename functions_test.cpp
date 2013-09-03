/*
 * function_test.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#include "functions.h"

#include<cppunit/TestFixture.h>
#include<cppunit/Test.h>
#include<cppunit/TestAssert.h>
#include<cppunit/TestCaller.h>
#include<cppunit/TestSuite.h>

using namespace CppUnit;

class FunctionsTest: public CppUnit::TestFixture {
public:
	void rosenbrockTest() {
		RosenbrocksFunction r;
		Function* f = &r;
		Point p(r.dim);
		CPPUNIT_ASSERT(r.calc(p) == 1.0);
		CPPUNIT_ASSERT(f->calc(p) == 1.0);
		p.setCrd(0, 1);
		p.setCrd(1, 1);
		CPPUNIT_ASSERT(r.calc(p) == 0.0);
		CPPUNIT_ASSERT(f->calc(p) == 0.0);
	}

	void function1Test() {
		Function1 f1;
		Function* f = &f1;
		Point p(f1.dim);
		CPPUNIT_ASSERT(f1.calc(p) == 14);
		CPPUNIT_ASSERT(f->calc(p) == 14);
		p.setCrd(0, 1);
		p.setCrd(1, 2);
		p.setCrd(2, 3);
		CPPUNIT_ASSERT(f1.calc(p) == 0);
		CPPUNIT_ASSERT(f->calc(p) == 0);
	}

	void simpleQuadFunctionTest() {
		SimpleQuadFunction sqf;
		Function* f = &sqf;
		Point p(sqf.dim);
		CPPUNIT_ASSERT(sqf.calc(p) == 0);
		CPPUNIT_ASSERT(f->calc(p) == 0);
		p.setCrd(0, 1);
		p.setCrd(1, 1);
		CPPUNIT_ASSERT(sqf.calc(p) == 2);
		CPPUNIT_ASSERT(f->calc(p) == 2);
	}

	static Test* suite() {
		TestSuite* testsSuite = new TestSuite("FunctionsTest");
		testsSuite->addTest(new TestCaller<FunctionsTest>("rosenbrockTest", &FunctionsTest::rosenbrockTest));
		testsSuite->addTest(new TestCaller<FunctionsTest>("function1Test", &FunctionsTest::function1Test));
		testsSuite->addTest(new TestCaller<FunctionsTest>("simpleQuadFunctionTest", &FunctionsTest::simpleQuadFunctionTest));

		return testsSuite;
	}
};

