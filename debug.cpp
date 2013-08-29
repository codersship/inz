/*
 * Debug.cpp
 *
 *  Created on: 29 sie 2013
 *      Author: Comarch
 */

#include"debug.h"
#include<ctime>

Debug::Debug() {
	//std::fstream fs;
	stream.open("nm.log", std::fstream::out);
}

/*Debug::Debug(std::ostream& stream) {
	this->stream = stream;
	stream.open();
}*/

Debug::~Debug() {
	//if (typeid(stream) == typeid(std::fstream) )
		stream.close();
}

void Debug::log(std::string logComunicate) {
	time_t now = time(NULL);
	stream << ctime(&now)<<'\t'<< logComunicate << '\n';
}

Debug::Debug(std::string filename) {
	//std::fstream fs;
	stream.open(filename.c_str(), std::fstream::out);
}
