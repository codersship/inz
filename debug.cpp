/*
 * Debug.cpp
 *
 *  Created on: 29 sie 2013
 *      Author: Comarch
 */

#include"debug.h"
#include<ctime>

Debug::Debug() {
}

Debug::~Debug() {
}

void Debug::log() {
	/*time_t now = time(NULL);
	stream.open(filename.c_str(), std::fstream::app);
	stream << ctime(&now)<<'\t'<< ss.str() << '\n';
	stream.close();
	ss.flush();
	ss.clear();*/
}

Debug::Debug(const std::string &filename) {
	this->filename = filename;
}
