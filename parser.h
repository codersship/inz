/*
 * Parser.h
 *
 *  Created on: Sep 4, 2013
 *      Author: statek
 */

#ifndef PARSER
#define PARSER

#include "functions.h"
#include "nelderMead.h"

class Parser {
public:
	int size;
	char algorithm;
	Function *function;
	nmParams nmparams;

	Parser();
	~Parser();
	Parser(int argc, char** argv);
};

#endif /* PARSER */
