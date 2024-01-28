#include "function.h"

// Methods implementation
double Function::evaluate(double x) {
	return pow(x, 2) - (5 * x);
}

double Function::evaluateIteraction(double x) {
    return sqrt(5*x);
}

std::string Function::toString() {
	return "f(x) = x^2 - 5x";
}
