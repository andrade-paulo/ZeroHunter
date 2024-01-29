#pragma once

#include <string>
#include <math.h>

class Function {
private:
	std::string expression;
public:
	double evaluate(double);
	double evaluateIteraction(double, double h = 0);
	double evaluateDerivative(double, double);

	std::string toString();
};
