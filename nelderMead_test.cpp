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
//TODO napisac testy
	void creationTest() {
		NelderMead nm;
		Point n;
		CPPUNIT_ASSERT(nm.getIterations() == 0);
		CPPUNIT_ASSERT(nm.getResult() == n);
		CPPUNIT_ASSERT(nm.dim==DIM);
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
		Function* f = new Function1();
		NelderMead nm(f);
		Point p[f->dim + 1];
		for (int i=0; i < (f->dim + 1); ++i)
			p[i].randomizeCoordinates();
		nm.setPoints(p);
		//nm.run();
		nm.getIterations();
		for (int i = 0; i < f->dim; ++i) {
		//	CPPUNIT_ASSERT(nm.getResult().getCrd(i) <= f.optimum.getCrd(i) + nm.params.epsilon);
		//	CPPUNIT_ASSERT(nm.getResult().getCrd(i) >= f.optimum.getCrd(i) - nm.params.epsilon);
		}
	}

	static Test* suite() {
		TestSuite* testsSuite = new TestSuite("NelderMeadTest");
		testsSuite->addTest(new TestCaller<NelderMeadTest>("creationTest", &NelderMeadTest::creationTest));
		testsSuite->addTest(new TestCaller<NelderMeadTest>("calculateTest", &NelderMeadTest::calculateTest));
//		testsSuite->addTest(new TestCaller<NelderMeadTest>("testOddition", &NelderMeadTest::statesTest));

		return testsSuite;
	}
};
