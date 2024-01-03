#include <vector>
#include "Iteration.h"
#include "Interval.h"
#include "Function.h"

class Solution
{
private:
	std::vector<Iteration> iterations;
	double approximation[2];
	Interval startingInterval;
	double errorMargin;
	Function function;

public:
	Solution(std::vector<Iteration>, double, Interval, double, Function);
};

