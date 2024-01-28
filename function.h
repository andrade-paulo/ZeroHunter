#pragma once

#include <string>
#include <math.h>

class Function {
private:
	std::string expression;
public:
	double evaluate(double);
    double evaluateIteraction(double);

	std::string toString();
};
