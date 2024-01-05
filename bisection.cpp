#include "Bisection.h"
using namespace std;


Bisection::Bisection() {
	this->function = Function();
	this->initialInterval = Interval();
	this->errorMargin = 0.0001;
	this->maxIterations = this->interationsNumber(this->initialInterval, this->errorMargin);
}


Bisection::Bisection(Function function, double errorMargin, Interval initialInterval) {
	this->function = function;
	this->initialInterval = initialInterval;
	this->errorMargin = errorMargin;
	this->maxIterations = this->interationsNumber(initialInterval, errorMargin);
}


Bisection::Bisection(Function function, double errorMargin, Interval initialInterval, unsigned int maxIterations) {
	this->function = function;
	this->initialInterval = initialInterval;
	this->errorMargin = errorMargin;
	this->maxIterations = maxIterations;
}


unsigned int Bisection::interationsNumber(Interval interval, double error) {
	return (unsigned int) ceil( (log(interval.getEnd() - interval.getStart()) - log(error)) / log(2) );
}


Solution Bisection::evaluate() {
	double approximation, y;

	vector<Iteration> iterations;
	iterations.push_back({ initialInterval });

	double a, b;
	
	for (unsigned int j = 0; j < iterations.size(); j++) {
		// Intervalo atual
		a = iterations[j].interval.getStart();
		b = iterations[j].interval.getEnd();

		// Aproximação e valor da função no ponto
		approximation = (a + b) / 2;
		y = this->function.evaluate(approximation);

		// Atualização da iteração atual
		iterations[j].approximation[0] = approximation;
		iterations[j].approximation[1] = y;
		iterations[j].interationNumber = j;

		cout << "-----------------------------------" << endl
			<< "Iteration: " << j << endl
			<< "Iterations' vector size: " << iterations.size() << endl
			<< "Interval: " << a << ", " << b << endl
			<< "Aproximation: " << approximation << endl
			<< "Function value: y = " << y << " | f(a) = " << this->function.evaluate(a) << " | f(b) = " << this->function.evaluate(b) << endl
			<< "-----------------------------------" << endl << endl;

		// Condição de aceitação
		if (this->function.evaluate(a) * this->function.evaluate(b) < 0) {
			if (abs(y) < this->errorMargin || abs(approximation - a) < this->errorMargin || abs(approximation - b) < this->errorMargin) {
				return { iterations, {approximation, y} };
			}
		} else {
			if (abs(this->function.evaluate(a) < this->errorMargin)) {
				return { iterations, {a, this->function.evaluate(a)} };
			}
			else if (abs(this->function.evaluate(b) < this->errorMargin)) {
				return { iterations, {b, this->function.evaluate(b)} };
			}
		}
		
		// Se a função troca de sinal, então existe uma raiz no intervalo
		if (y * this->function.evaluate(a) < 0) {
			iterations.push_back({ Interval(a, approximation) });
		}
		else if (y * this->function.evaluate(b) < 0) {
			iterations.push_back({ Interval(approximation, b) });
		}
		// Se não, adiciona ambos os intervalos
		else {
			iterations.push_back({ Interval(a, approximation) });
			iterations.push_back({ Interval(approximation, b) });
		}

		if (j >= this->maxIterations) {
			throw exception("The method failed to find a solution wihin the max interations number");
		}
	}

	throw exception("The method failed to find a solution");
}


string Bisection::toString() {
	return "Function: " + this->function.toString() + "\n"
		+ "Error margin: " + to_string(this->errorMargin) + "\n"
		+ "Initial interval: " + this->initialInterval.toString() + "\n"
		+ "Max iterations: " + to_string(this->maxIterations);
}