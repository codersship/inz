/*
 * Parser.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: statek
 */

#include "parser.h"
#include <stdlib.h>

Parser::Parser() {
}

Parser::~Parser() {
	if (function!=0) delete function;
}

Parser::Parser(int argc, char** argv) {
	int i = 0;
	while (i < argc) {
		++i;
		if(argv[i]=="-nm") {
			algorithm = 'n';
		}
		if(argv[i]=="-f") {
			i++;
			if(argv[i]=="r") {
				function = new RosenbrocksFunction();
			}
			if(argv[i]=="sq") {
				function = new SimpleQuadFunction();
			}
			if(argv[i]=="f1") {
				function = new Function1();
			}
		}
		if(argv[i]=="-a") {
			++i;
			nmparams.alpha = atof(argv[i]);
		}
		if(argv[i]=="-b") {
			++i;
			nmparams.beta = atof(argv[i]);
		}if(argv[i]=="-g") {
			++i;
			nmparams.gamma = atof(argv[i]);
		}if(argv[i]=="-e") {
			++i;
			nmparams.epsilon = atof(argv[i]);
		}if(argv[i]=="-s") {
			++i;
			size = atof(argv[i]);
		}
	}
}
