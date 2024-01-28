#pragma once

#include "interval.h"

struct Iteration
{
	Interval interval;
	double approximation[2];
	unsigned int interationNumber;
};

struct IterationPoint
{
	double point;
	double approximation[2];
	unsigned int interationNumber;
};

// To-do: Abstrair melhor a iteração de intervalo e ponto
