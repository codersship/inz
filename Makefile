#Makefile
CXX=g++
TESTLIBS=-lcppunit
LIBS=-lpthread

all: test app

clean:
	touch o.o o.log o.ghc
	rm *.o *.log *.ghc

app: clean main.o point.o timer.o nelderMead.o cpuAlgorithms.o functions.o debug.o
	$(CXX) -g main.o point.o timer.o nelderMead.o cpuAlgorithms.o functions.o debug.o -o app $(LIBS)

test: clean main_test.o point.o timer.o nelderMead.o cpuAlgorithms.o functions.o debug.o
	$(CXX) -g main_test.o point.o timer.o nelderMead.o cpuAlgorithms.o functions.o debug.o -o test $(TESTLIBS) $(LIBS)

main.o: main.cpp
	$(CXX) -c -g main.cpp

main_test.o: main_test.cpp
	$(CXX) -c -g main_test.cpp

point_test.o: point.o point_test.cpp
	$(CXX) -c -g point_test.cpp

point.o: point.h point.cpp
	$(CXX) -c -g point.cpp

timer_test.o: timer.o timer_test.cpp
	$(CXX) -c -g timer_test.cpp

timer.o: timer.h timer.cpp
	$(CXX) -c -g timer.cpp

nelderMead_test.o: nelderMead.o nelderMead_test.cpp
	$(CXX) -c -g nelderMead_test.cpp

nelderMead.o: nelderMead.h nelderMead.cpp point.o
	$(CXX) -c -g nelderMead.cpp

cpuAlgorithms_test.o: cpuAlgorithms.o cpuAlgorithms_test.cpp
	$(CXX) -c -g cpuAlgorithms_test.cpp

cpuAlgorithms.o: cpuAlgorithms.h cpuAlgorithms.cpp
	$(CXX) -c -g cpuAlgorithms.cpp

functions_test.o: functions.o functions_test.cpp
	$(CXX) -c -g functions_test.cpp

functions.o: functions.h functions.cpp point.o
	$(CXX) -c -g functions.cpp
	
debug.o: debug.h debug.cpp 
	$(CXX) -c -g debug.cpp
