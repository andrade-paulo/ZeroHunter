#include "fixedPoint.h"
#include "function.h"
using namespace std;


FixedPoint::FixedPoint(Function function, Function iteractionFunction, double errorMargin, double initialPoint, unsigned int maxIterations) {
	this->function = function;
	this->iteractionFunction = iteractionFunction;
	this->errorMargin = errorMargin;
	this->initialPoint = initialPoint;
	this->maxIterations = maxIterations;
}

SolutionPoint FixedPoint::evaluate() {
	double approximation, y;

	vector<IterationPoint> iterations;
	iterations.push_back({ this->initialPoint });

	for (int i = 0; iterations.size() <= this->maxIterations; i++) {
		approximation = this->iteractionFunction.evaluateIteraction(iterations[i].point);
		y = this->function.evaluate(approximation);

		iterations[i].approximation[0] = approximation;
		iterations[i].approximation[1] = y;
		iterations[i].interationNumber = i;

		cout << "-----------------------------------" << endl
			<< "Interation: " << i << endl
			<< "Point: " << iterations[i].point << endl
			<< "Approximation: " << approximation << endl
			<< "Function value: " << y << endl 
			<< "-----------------------------------" << endl << endl;

		// Condição de aceitação
		if (iterations.size() >= 2) {
			if (abs( approximation - iterations[i-1].point ) < this->errorMargin) {
				return { iterations, {approximation, y} };
			}
		} 
        
        if (abs(approximation) < this->errorMargin) {
				return { iterations, {approximation, y} };
		} 

        iterations.push_back({ approximation });
	}

	throw runtime_error("The method failed to find a solution wihin the max interations number");
}


string FixedPoint::toString() {
	return "Function: " + this->function.toString() + "\n"
		+ "Iteration Function: " + this->iteractionFunction.toString() + "\n"
		+ "Error margin: " + std::to_string(this->errorMargin) + "\n"
		+ "Initial point: " + std::to_string(this->initialPoint) + "\n"
		+ "Max interations: " + std::to_string(this->maxIterations) + "\n";
}
