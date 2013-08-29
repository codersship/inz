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

class Debug {
	std::fstream stream;
public:
	Debug();
	//Debug(std::ostream& stream);
	Debug(std::string filename);
	~Debug();
	void log(std::string logComunicate);
};

#endif /* DEBUG */
