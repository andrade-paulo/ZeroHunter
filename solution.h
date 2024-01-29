#pragma once

#include <vector>
#include "iteration.h"
#include "interval.h"
#include "function.h"

struct Solution {
	std::vector<Iteration> iterations;
	double approximation[2];
};
