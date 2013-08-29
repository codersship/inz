/*
 * Debug.h
 *
 *  Created on: 29 sie 2013
 *      Author: Comarch
 */

#ifndef DEBUG
#define DEBUG

#include<iostream>

class Debug {
	std::ios stream;
public:
	Debug();
	Debug(std::ios stream);
	Debug(std::string filename);
	~Debug();
	void log(std::string logComunicate);
};

#endif /* DEBUG */
