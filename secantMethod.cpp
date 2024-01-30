#include "secantMethod.h"
using namespace std;


SecantMethod::SecantMethod(Function function, Function iteractionFunction, double errorMargin, double points[2], unsigned int maxIterations) {
	this->function = function;
	this->iteractionFunction = iteractionFunction;
	this->errorMargin = errorMargin;
	this->points[0] = points[0];
	this->points[1] = points[1];
	this->maxIterations = maxIterations;
}

Solution SecantMethod::evaluate() {
	double approximation, y;

	vector<Iteration> iterations;

	Iteration newIteration;
	newIteration.points[0] = this->points[0];
	newIteration.points[1] = this->points[1];

	iterations.push_back(newIteration);

	for (int i = 0; iterations.size() <= this->maxIterations; i++) {
		approximation = this->iteractionFunction.evaluateSecant(iterations[i].points[0], iterations[i].points[1]);
		
		y = this->function.evaluate(approximation);

		iterations[i].approximation[0] = approximation;
		iterations[i].approximation[1] = y;
		iterations[i].interationNumber = i;

		cout << "-----------------------------------" << endl
			<< "Interation: " << i << endl
			<< "Points: " << iterations[i].points[0] << " | " << iterations[i].points[1] << endl
			<< "Approximation: " << approximation << endl
			<< "Function value: " << y << endl 
			<< "-----------------------------------" << endl << endl;

		// Condição de aceitação
		if (iterations.size() >= 2) {
			if (abs( approximation - iterations[i-1].points[1] ) < this->errorMargin) {
				return { iterations, {approximation, y} };
			}
		} 
        
        if (abs(y) < this->errorMargin) {
				return { iterations, {approximation, y} };
		} 

		newIteration.points[0] = iterations[i].points[1];
		newIteration.points[1] = approximation;

		iterations.push_back(newIteration);
	}

	throw runtime_error("The method failed to find a solution wihin the max interations number");
}


string SecantMethod::toString() {
	return "Function: " + this->function.toString() + "\n"
		+ "Iteration Function: " + this->iteractionFunction.toString() + "\n"
		+ "Error margin: " + std::to_string(this->errorMargin) + "\n"
		+ "Initial points: " + std::to_string(this->points[0]) + " | " + std::to_string(this->points[1]) + "\n"
		+ "Max interations: " + std::to_string(this->maxIterations) + "\n";
}
