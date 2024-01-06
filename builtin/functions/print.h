//
// Created by Sharll on 2023/5/13.
//

#ifndef UNTITLED6_PRINT_H
#define UNTITLED6_PRINT_H

#include "../../PokFunction.h"

class print: PokFunction {
public:
		PokStuff* call(vector<PokStuff*> arguments) override {
			for(PokStuff *i: arguments){
				cout << i->toString() << endl;
			}
		}
};

#endif //UNTITLED6_PRINT_H
