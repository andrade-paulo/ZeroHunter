#include "function.h"

// Methods implementation
double Function::evaluate(double x) {
	return pow(x, 2) + x - 6;
}

double Function::evaluateIteraction(double x) {
    return sqrt(6 - x);
}

std::string Function::toString() {
	return "f(x) = x^2 - 5x";
}
