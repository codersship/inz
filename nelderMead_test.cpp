/*
 * nelderMead_test.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: statek
 */

#include "nelderMead.h"
#include "functions.h"

#include<cppunit/TestFixture.h>
#include<cppunit/Test.h>
#include<cppunit/TestAssert.h>
#include<cppunit/TestCaller.h>
#include<cppunit/TestSuite.h>

using namespace CppUnit;

class NelderMeadTest: public CppUnit::TestFixture {
public:
	void creationTest() {
		SimpleQuadFunction sqf;
		NelderMead nm(&sqf);
		Point n;
		CPPUNIT_ASSERT(nm.getIterations() == 0);
		CPPUNIT_ASSERT(nm.getResult() == n);
		CPPUNIT_ASSERT(nm.dim == sqf.dim);
		CPPUNIT_ASSERT(nm.points == 0);

		CPPUNIT_ASSERT(nm.idx.x1 == 0);
		CPPUNIT_ASSERT(nm.idx.xn1 == 0);
		CPPUNIT_ASSERT(nm.idx.xn == 0);

		CPPUNIT_ASSERT(nm.params.alpha==ALPHA);
		CPPUNIT_ASSERT(nm.params.beta==BETA);
		CPPUNIT_ASSERT(nm.params.gamma==GAMMA);
		CPPUNIT_ASSERT(nm.params.epsilon==EPSILON);
	}

	void calculateTest() {
		SimpleQuadFunction sqf;
		Function* f = &sqf;
		NelderMead nm(f);
		Point** p = new Point*[f->dim + 1];
		for (int i = 0; i < (f->dim + 1); ++i) {
			p[i] = new Point(f->dim);
			p[i]->randomizeCoordinates();
		}
		nm.setPoints(p);
		nm.run();
		int iterations = nm.getIterations();
		Point result = nm.getResult();
		for (int i = 0; i < f->dim; ++i) {
			CPPUNIT_ASSERT(nm.getResult().getCrd(i) <= f->optimum->getCrd(i) + nm.params.epsilon);
			CPPUNIT_ASSERT(nm.getResult().getCrd(i) >= f->optimum->getCrd(i) - nm.params.epsilon);
		}
		for (int i = 0; i < (f->dim + 1); ++i) {
			delete p[i];
		}

	}

	static Test* suite() {
		TestSuite* testsSuite = new TestSuite("NelderMeadTest");
		testsSuite->addTest(new TestCaller<NelderMeadTest>("creationTest", &NelderMeadTest::creationTest));
		testsSuite->addTest(new TestCaller<NelderMeadTest>("calculateTest", &NelderMeadTest::calculateTest));

		return testsSuite;
	}
};
