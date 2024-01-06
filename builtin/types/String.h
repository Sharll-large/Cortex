//
// Created by Sharll on 2024/1/5.
//

#ifndef CORTEX_STRING_H
#define CORTEX_STRING_H

#include "Base.h"

class String : Base {
		std::string val;
		std::string toString() override {
			return val;
		}
};

#endif //CORTEX_STRING_H
