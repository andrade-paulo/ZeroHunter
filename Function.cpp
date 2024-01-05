#include "Function.h"

// Methods implementation
double Function::evaluate(double x) {
	return pow(x, 2) + 5 * x;
}


std::string Function::toString() {
	return "f(x) = x^2 + 5x";
}