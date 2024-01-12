#include "Function.h"

// Methods implementation
double Function::evaluate(double x) {
	return sin(2*x) + cos(x/2);
}


std::string Function::toString() {
	return "f(x) = x^2 + 5x";
}