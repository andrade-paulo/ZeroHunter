#include "interval.h"

struct Iteration
{
	Interval interval;
	double approximation[2];
	unsigned int interationNumber;
};