#pragma once

#include <iostream>
#include <math.h>
#include <vector>

#include "interval.h"
#include "iteration.h"
#include "function.h"
#include "solution.h"

class FalsePosition
{
private:
	Function function;
	double errorMargin;
	Interval initialInterval;
	unsigned int maxIterations;

public:
	FalsePosition(Function, double, Interval);

	FalsePosition(Function, double, Interval, unsigned int);

	Solution evaluate();

	unsigned int interationsNumber(Interval, double);

	std::string toString();
};

