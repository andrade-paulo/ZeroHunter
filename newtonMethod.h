#pragma once

#include <iostream>
#include <math.h>
#include <vector>

#include "iteration.h"
#include "function.h"
#include "solution.h"

class NewtonMethod
{
private:
	Function function;
	Function iteractionFunction;
	double errorMargin;
	double initialPoint;
	unsigned int maxIterations;

public:
	NewtonMethod(Function, Function, double, double, unsigned int);

	Solution evaluate();

	std::string toString();
};

