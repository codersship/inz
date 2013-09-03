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
public:
	Debug();
	//Debug(std::ostream& stream);
	Debug(const std::string &filename);
	~Debug();
	void log(const std::string logComunicate);
};

#endif /* DEBUG */
