//
// Created by Sharll on 2023/5/24.
//

#include <iostream>

using namespace std;

#ifndef UNTITLED6_EXCEPTION_H
#define UNTITLED6_EXCEPTION_H

void pok_exception(char* filename, int line, char* info) {
	cerr << "Exception in file \"" << filename << "\", line " << line << ":\n\t" << info;
	exit(-1);
}

#endif //UNTITLED6_EXCEPTION_H
