#include "falsePosition.h"
#include "function.h"
using namespace std;


FalsePosition::FalsePosition(Function function, double errorMargin, Interval initialInterval, unsigned int maxIterations) {
	this->function = function;
	this->errorMargin = errorMargin;
	this->initialInterval = initialInterval;
	this->maxIterations = maxIterations;
}


FalsePosition::FalsePosition(Function function, double errorMargin, Interval initialInterval) {
	this->function = function;
	this->errorMargin = errorMargin;
	this->initialInterval = initialInterval;
	this->maxIterations = this->interationsNumber(initialInterval, errorMargin);
}


unsigned int FalsePosition::interationsNumber(Interval interval, double error) {
	return (unsigned int) ceil( (log(interval.getEnd() - interval.getStart()) - log(error)) / log(2) );
}


Solution FalsePosition::evaluate() {
	double aproximation, y;

	int maxInterations = this->interationsNumber(this->initialInterval, this->errorMargin);

	vector<Iteration> iterations;
	iterations.push_back({ initialInterval });

	double a, b;

	for (int j = 0; j < iterations.size(); j++) {
		a = iterations[j].interval.getStart();
		b = iterations[j].interval.getEnd();

		aproximation = (a * abs(this->function.evaluate(b)) + b * abs(this->function.evaluate(a))) / (abs(this->function.evaluate(a)) + abs(this->function.evaluate(b)));
		y = this->function.evaluate(aproximation);

		iterations[j].approximation[0] = aproximation;
		iterations[j].approximation[1] = y;
		iterations[j].interationNumber = j;

		cout << "-----------------------------------" << endl
			<< "Interation: " << j << endl
			<< "Intervals size: " << iterations.size() << endl
			<< "Interval: " << a << ", " << b << endl
			<< "Aproximation: " << aproximation << endl
			<< "Function value: y = " << y << " | f(a) = " << this->function.evaluate(a) << " | f(b) = " << this->function.evaluate(b) << endl
			<< "-----------------------------------" << endl << endl;

		// Condição de aceitação
		if (this->function.evaluate(a) * this->function.evaluate(b) < 0) {
			if (abs(y) < this->errorMargin || abs(aproximation - a) < this->errorMargin || abs(aproximation - b) < this->errorMargin) {
				return { iterations, {aproximation, y} };
			}
		} else {
			if (abs(this->function.evaluate(a) < this->errorMargin)) {
				return { iterations, {a, this->function.evaluate(a)} };
			} else if (abs(this->function.evaluate(b) < this->errorMargin)) {
				return { iterations, {b, this->function.evaluate(b)} };
			}
		}

		// Se a função troca de sinal, então existe uma raiz no intervalo
		if (y * this->function.evaluate(a) < 0) {
			iterations.push_back({ Interval(a, aproximation) });
		}
		else if (y * this->function.evaluate(b) < 0) {
			iterations.push_back({ Interval(aproximation, b) });
		}
		// Se não, adiciona ambos os intervalos
		else {
			iterations.push_back({ Interval(a, aproximation) });
			iterations.push_back({ Interval(aproximation, b) });
		}

		if (j >= maxInterations) {
			throw runtime_error("The method failed to find a solution wihin the max interations number");
		}
	}

	throw runtime_error("The method failed to find a solution");
}


string FalsePosition::toString() {
	return "Function: " + this->function.toString() + "\n"
		+ "Error margin: " + std::to_string(this->errorMargin) + "\n"
		+ "Initial interval: " + initialInterval.toString() + "\n"
		+ "Max interations: " + std::to_string(this->maxIterations) + "\n";
}
