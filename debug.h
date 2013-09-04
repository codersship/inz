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
#include<string>

class Debug {
	std::fstream stream;
	std::string filename;
	std::stringstream ss;
public:
	Debug();
	Debug(const std::string &filename);
	~Debug();
	void log();
};

#endif /* DEBUG */
