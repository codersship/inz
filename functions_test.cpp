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
		RosenbrocksFunction* r = new RosenbrocksFunction();
		Function* f = (Function*) r;
		Function* fr = r;
		Point p(r->dim);
		double result = r->calc(p);
		CPPUNIT_ASSERT(result == 1.0);
		CPPUNIT_ASSERT(f->calc(p) == 1.0);
		CPPUNIT_ASSERT(fr->calc(p) == 1.0);
		p.setCrd(0, 1);
		p.setCrd(1, 1);
		CPPUNIT_ASSERT(r->calc(p) == 0.0);
		CPPUNIT_ASSERT(f->calc(p) == 0.0);
		CPPUNIT_ASSERT(fr->calc(p) == 0.0);
	}

	void function1Test() {
		Function1* f1 = new Function1();
		Function* f = (Function*) f1;
		Function* fr = f1;
		Point p(f1->dim);
		CPPUNIT_ASSERT(f1->calc(p) == 14);
		CPPUNIT_ASSERT(f->calc(p) == 14);
		CPPUNIT_ASSERT(fr->calc(p) == 14);
		p.setCrd(0, 1);
		p.setCrd(1, 2);
		p.setCrd(2, 3);
		CPPUNIT_ASSERT(f1->calc(p) == 0);
		CPPUNIT_ASSERT(f->calc(p) == 0);
		CPPUNIT_ASSERT(fr->calc(p) == 0);
	}

	static Test* suite() {
		TestSuite* testsSuite = new TestSuite("NelderMeadTest");
		//testsSuite->addTest(new TestCaller<FunctionsTest>("rosenbrockTest", &FunctionsTest::rosenbrockTest));
		testsSuite->addTest(new TestCaller<FunctionsTest>("function1Test", &FunctionsTest::function1Test));

		return testsSuite;
	}
};

