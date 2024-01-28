#pragma once

#include <iostream>
#include <math.h>
#include <vector>

#include "interval.h"
#include "iteration.h"
#include "function.h"
#include "solution.h"

class FixedPoint
{
private:
	Function function;
	Function iteractionFunction;
	double errorMargin;
	double initialPoint;
	unsigned int maxIterations;

public:
	FixedPoint(Function, Function, double, double, unsigned int);

	SolutionPoint evaluate();

	std::string toString();
};

