#include "falsePosition.h"
using namespace std;

double falsePositionMethod(Interval initialInterval, double error) {
	double aproximation, y;

	int maxInterations = interationsNumber(initialInterval.getStart(), initialInterval.getEnd(), error);

	vector<Interval> intervals;
	intervals.push_back(initialInterval);

	int iterations = 0;

	double a, b;

	for (int j = 0; j < intervals.size(); j++) {
		a = intervals[j].getStart();
		b = intervals[j].getEnd();

		aproximation = (a * abs(function(b)) + b * abs(function(a))) / (abs(function(a)) + abs(function(b)));
		y = function(aproximation);

		cout << "-----------------------------------" << endl
			<< "Interation: " << iterations << endl
			<< "Intervals size: " << intervals.size() << endl
			<< "Interval: " << a << ", " << b << endl
			<< "Aproximation: " << aproximation << endl
			<< "Function value: y = " << y << " | f(a) = " << function(a) << " | f(b) = " << function(b) << endl
			<< "-----------------------------------" << endl << endl;

		// Condição de aceitação
		if (function(a) * function(b) < 0) {
			if (abs(y) < error || abs(aproximation - a) < error || abs(aproximation - b) < error) {
				return aproximation;
			}
		} else {
			if (abs(function(a) < error)) {
				return a;
			} else if (abs(function(b) < error)) {
				return b;
			}
		}

		// Se a função troca de sinal, então existe uma raiz no intervalo
		if (y * function(a) < 0) {
			intervals.push_back(Interval(a, aproximation));
		}
		else if (y * function(b) < 0) {
			intervals.push_back(Interval(aproximation, b));
		}
		// Se não, adiciona ambos os intervalos
		else {
			intervals.push_back(Interval(a, aproximation));
			intervals.push_back(Interval(aproximation, b));
		}

		if (iterations++ > maxInterations) {
			throw exception("The method failed to find a solution wihin the max interations number");
		}
	}

	throw exception("The method failed to find a solution");
}