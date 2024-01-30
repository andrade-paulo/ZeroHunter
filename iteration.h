#pragma once

#include "interval.h"

struct Iteration
{
	Interval interval;
	double point;
	double approximation[2];
	unsigned int interationNumber;
	double points[2];
};
