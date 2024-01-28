#pragma once

#include <vector>
#include "iteration.h"
#include "interval.h"
#include "function.h"

struct Solution {
	std::vector<Iteration> iterations;
	double approximation[2];
};

struct SolutionPoint {
    std::vector<IterationPoint> iterations;
    double approximation[2];
};

// To-do: Abstrair melhor a solução ou a iteração com ponto ou intervalo
