/*
 * Debug.cpp
 *
 *  Created on: 29 sie 2013
 *      Author: Comarch
 */

#include "Debug.h"

Debug::Debug() {
	std::fstream fstream;
	stream = fstream.open("nm.log",std::fstream::out);
}

Debug::Debug(std::ios stream) {
	this->stream = stream;
	stream.open();
}

Debug::~Debug() {
	stream.close();
}

void Debug::log(std::string logComunicate) {
	stream << logComunicate;
}

Debug::Debug(std::string filename) {
	std::fstream fstream;
	stream = fstream.open(filename, std::fstream::out);
}
