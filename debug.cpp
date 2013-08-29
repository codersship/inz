/*
 * Debug.cpp
 *
 *  Created on: 29 sie 2013
 *      Author: Comarch
 */

#include"debug.h"

Debug::Debug() {
	std::fstream fs;
	stream = fs.open("nm.log",std::fstream::out);
}

Debug::Debug(std::ostream stream) {
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
	std::fstream fs;
	stream = fs.open(filename, std::fstream::out);
}
