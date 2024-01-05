#include "ZeroHunter.h"
using namespace std;

int main() {
	// Bisection test
	Interval interv(-4, 2);

	Function func;

	Solution solutionBisection;
	Solution solutionFalsePosition;

	cout << "-=-=- Bisection method -=-=-" << endl;
	try {
		Bisection bisection(func, 0.0001, interv);

		cout << bisection.toString() << endl << endl;

		solutionBisection = bisection.evaluate();

		cout << "Solution:" << endl
			<< "X Approximation: " << solutionBisection.approximation[0] << endl
			<< "Y Approximation: " << solutionBisection.approximation[1] << endl << endl;
	}
	catch (exception e) { 
		cout << e.what() << endl;
	}

	cout << endl << endl;

	cout << "-=-=- False Position method -=-=-" << endl;
	try {
		FalsePosition falsePosition(func, 0.00001, interv);

		cout << falsePosition.toString() << endl << endl;
		solutionFalsePosition = falsePosition.evaluate();

		cout << "Solution:" << endl
			<< "X Approximation: " << solutionFalsePosition.approximation[0] << endl
			<< "Y Approximation: " << solutionFalsePosition.approximation[1] << endl << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	return 0;
}

