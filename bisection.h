#pragma once

#include <iostream>
#include <math.h>
#include <vector>

#include "interval.h"
#include "iteration.h"
#include "function.h"
#include "solution.h"

class Bisection
{
private:
	Function function;
	double errorMargin;
	Interval initialInterval;
	unsigned int maxIterations;

public:
	Bisection();

	Bisection(Function, double, Interval);

	Bisection(Function, double, Interval, unsigned int);

	unsigned int interationsNumber(Interval, double);

	Solution evaluate();

	std::string toString();
};
