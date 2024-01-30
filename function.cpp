#include "function.h"
#include <stdexcept>
#include <iostream>

// Methods implementation
double Function::evaluate(double x) {
	//return pow(x, 2) + x - 6;
	return 2 * cos(x) - exp(2 * x);
}

double Function::evaluateIteraction(double x, double h) {
	double ans;

	if (h == 0) {
		ans = sqrt(6 - x);
		//ans = pow((5 * exp(-1 * x)), 2);
	}
	else {
		if (this->evaluateDerivative(x, h) == 0)
		    throw std::runtime_error("The method found a zero derivative");
		
		std::cout << x - (this->evaluate(x) / this->evaluateDerivative(x, h)) << std::endl;
		ans = x - (this->evaluate(x) / this->evaluateDerivative(x, h));
    }
	
	return ans;
}

double Function::evaluateSecant(double x0, double x) {
    // ( x1 * f(x) - x * f(x1) ) / ( f(x) - f(x1) )
    return (x0 * this->evaluate(x) - x * this->evaluate(x0)) / (this->evaluate(x) - this->evaluate(x0));
}

double Function::evaluateDerivative(double x, double h) {
	std::cout << (this->evaluate(x + h) - this->evaluate(x - h)) / (2*h) << std::endl;
	return (this->evaluate(x + h) - this->evaluate(x - h)) / (2*h);
}

std::string Function::toString() {
	return "f(x) = x^2 + x - 6";
}
