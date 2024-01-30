#pragma once

#include <iostream>
#include <math.h>
#include <vector>

#include "interval.h"
#include "iteration.h"
#include "function.h"
#include "solution.h"

class SecantMethod
{
private:
	Function function;
	Function iteractionFunction;
	double errorMargin;
	double points[2];
	unsigned int maxIterations;

public:
	SecantMethod(Function, Function, double, double[2], unsigned int);

	Solution evaluate();

	std::string toString();
};

