//
// Created by Sharll on 2023/5/13.
//

#ifndef UNTITLED6_INTEGER_H
#define UNTITLED6_INTEGER_H

#include "Base.h"

class Integer: Base {
public:
		long long val{};
		std::string toString() override {
			return std::to_string(val);
		}
};

#endif //UNTITLED6_INTEGER_H
