#pragma once

#include <vector>
#include "Iteration.h"
#include "Interval.h"
#include "Function.h"

struct Solution {
	std::vector<Iteration> iterations;
	double approximation[2];
};

