#pragma once

#include <string>

class Function {
private:
	std::string expression;
public:
	double evaluate(double x);

	std::string toString();
};
