/*
 * timer_test.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: statek
 */

#include "timer.h"

#include<cppunit/TestFixture.h>
#include<cppunit/Test.h>
#include<cppunit/TestAssert.h>
#include<cppunit/TestCaller.h>
#include<cppunit/TestSuite.h>

using namespace CppUnit;

class TimerTest: public CppUnit::TestFixture {
public:

	void creationTest() {
		Timer t;
		CPPUNIT_ASSERT(t.state == 'n');
		Timer* s = new Timer(true);
		CPPUNIT_ASSERT(s->state == 'm');
	}
	void measureTest() {
		Timer t;
		t.start();
		sleep(10);
		t.stop();
		CPPUNIT_ASSERT(t.delta() >= 10.0);
		CPPUNIT_ASSERT(t.delta() <= 11.0);
	}
	void statesTest() {
		Timer t;
		CPPUNIT_ASSERT(t.state == 'n');
		//CPPUNIT_ASSERT_THROW(t.stop(), TimerException);
		//CPPUNIT_ASSERT_THROW(t.delta(), TimerException);
		t.start();
		CPPUNIT_ASSERT(t.state == 'm');
		//CPPUNIT_ASSERT_THROW(t.start(), TimerException);
		//CPPUNIT_ASSERT_THROW(t.delta(), TimerException);
		t.stop();
		CPPUNIT_ASSERT(t.state == 's');
		//CPPUNIT_ASSERT_THROW(t.stop(), TimerException);
		Timer s(true);
		CPPUNIT_ASSERT(s.state == 'm');
	}
	void exceptionsTest() {
		// TODO
	}
	static Test* suite() {
		TestSuite* testsSuite = new TestSuite("TimerTest");
		testsSuite->addTest(new TestCaller<TimerTest>("Creation Test", &TimerTest::creationTest));
		testsSuite->addTest(new TestCaller<TimerTest>("Measure Test", &TimerTest::measureTest));
		testsSuite->addTest(new TestCaller<TimerTest>("States Test", &TimerTest::statesTest));
		testsSuite->addTest(new TestCaller<TimerTest>("Exceptions Test", &TimerTest::exceptionsTest));

		return testsSuite;
	}
};
