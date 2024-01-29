#include "function.h"
#include <stdexcept>
#include <iostream>

// Methods implementation
double Function::evaluate(double x) {
	return pow(x, 2) + x - 6;
}

double Function::evaluateIteraction(double x, double h) {
	double ans;

	if (h == 0) {
		ans = sqrt(6 - x);
	}
	else {
		if (this->evaluateDerivative(x, h) == 0)
			throw std::runtime_error("The method found a zero derivative");
		
		ans = x - (this->evaluate(x) / this->evaluateDerivative(x, h));
	}
	
	return ans;
}

double Function::evaluateDerivative(double x, double h) {
	return (this->evaluate(x + h) - this->evaluate(x - h)) / (2*h);
}

std::string Function::toString() {
	return "f(x) = x^2 + x - 6";
}
