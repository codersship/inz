/*
 * point_test.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: statek
 */

#include"point.h"

#include<cppunit/TestFixture.h>
#include<cppunit/Test.h>
#include<cppunit/TestAssert.h>
#include<cppunit/TestCaller.h>
#include<cppunit/TestSuite.h>

using namespace CppUnit;

#define DIM 2

class PointTest: public CppUnit::TestFixture {
public:

	void creationTest() {
		Point p(DIM), r(DIM);
		p.randomizeCoordinates();
		r = p;
		CPPUNIT_ASSERT(r == p);
		CPPUNIT_ASSERT(p == r);
		Point* s = new Point(p);
		CPPUNIT_ASSERT(*s == p);
		CPPUNIT_ASSERT(p == *s);
		delete s;
	}

	void additionTest() {
		Point p(DIM), r(DIM), z(DIM);
		p.randomizeCoordinates();
		CPPUNIT_ASSERT(z + p == p);
		CPPUNIT_ASSERT(z + z == z);
		r.randomizeCoordinates();
		Point s = p + r;
		CPPUNIT_ASSERT(s == p + r);
	}

	void multiplicationTest() {
		Point z(DIM), p(DIM);
		CPPUNIT_ASSERT(z == z * 10);
		CPPUNIT_ASSERT(z == z * 0.73);
		p.randomizeCoordinates();
		CPPUNIT_ASSERT(z == p * 0);
		CPPUNIT_ASSERT(z == p * 0.0);
		CPPUNIT_ASSERT(p + p == p * 2);
		CPPUNIT_ASSERT(p + p == p * 2.0);
	}

	void divisionTest() {
		Point z(DIM), p(DIM);
		CPPUNIT_ASSERT(z / 2 == z);
		p.randomizeCoordinates();
		CPPUNIT_ASSERT_THROW(p / 0.0, std::invalid_argument);
		CPPUNIT_ASSERT_THROW(p / 0, std::invalid_argument);
		CPPUNIT_ASSERT(p / 1 == p);
		Point r = p + p;
		CPPUNIT_ASSERT(r / 2 == p);
		CPPUNIT_ASSERT(r / 2.0 == p);
	}

	void subtractionTest() {
		Point z(DIM), p(DIM);
		p.randomizeCoordinates();
		CPPUNIT_ASSERT(z - z == z);
		CPPUNIT_ASSERT(p - z == p);
	}

	void wrongCoordinatesTest() throw (std::invalid_argument) {
		Point p(DIM);
		p.randomizeCoordinates();
		CPPUNIT_ASSERT_THROW(p.getCrd(DIM+1), std::invalid_argument);
		CPPUNIT_ASSERT_THROW(p.setCrd(DIM+1,0), std::invalid_argument);
	}

	void memoryTest() {
		CPPUNIT_ASSERT(Point::counter == 0);
	}
	static Test* suite() {
		TestSuite* testsSuite = new TestSuite("TestPoint");
		testsSuite->addTest(new TestCaller<PointTest>("memory test", &PointTest::memoryTest));
		testsSuite->addTest(new TestCaller<PointTest>("creation test", &PointTest::creationTest));
		testsSuite->addTest(new TestCaller<PointTest>("addition test", &PointTest::additionTest));
		testsSuite->addTest(new TestCaller<PointTest>("subtraction test", &PointTest::subtractionTest));
		testsSuite->addTest(new TestCaller<PointTest>("multiplication test", &PointTest::multiplicationTest));
		testsSuite->addTest(new TestCaller<PointTest>("division test", &PointTest::divisionTest));
		testsSuite->addTest(new TestCaller<PointTest>("wrong coordinates test", &PointTest::wrongCoordinatesTest));

		return testsSuite;
	}
};
