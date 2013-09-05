/*
 * Debug.h
 *
 *  Created on: 29 sie 2013
 *      Author: Comarch
 */

#ifndef DEBUG
#define DEBUG

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

class Debug {
private:
	std::fstream stream;
	std::string filename;

public:
	std::stringstream ss;
	Debug();
	Debug(const std::string &filename);
	~Debug();
	void log();
};

#endif /* DEBUG */
