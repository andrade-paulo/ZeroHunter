#include "ZeroHunter.h"
using namespace std;

int main() {

	Function func;
	double a, b, errorMargin;
	char method;

	cout << "Initial interval: ";
	cin >> a >> b;

	Interval interv(a, b);
	
	cout << endl;

	cout << "Error margin: ";
	cin >> errorMargin;

	cout << endl;

	cout << "Choose method" << endl
		<< "1. Bisection" << endl
		<< "2. False Position" << endl
		<< ": ";
	cin >> method;

	cout << endl << endl;

	Solution solution;
	
	switch (method) {
	case '1':
		cout << "-=-=- Bisection method -=-=-" << endl;
		
		try {
			Bisection bisection(func, 0.0001, interv);

			cout << bisection.toString() << endl << endl;

			solution = bisection.evaluate();

			cout << "Solution:" << endl
				<< "X Approximation: " << solution.approximation[0] << endl
				<< "Y Approximation: " << solution.approximation[1] << endl << endl;
		}
		catch (exception e) {
			cout << e.what() << endl;
		}

		break;

	case '2':
		cout << "-=-=- False Position method -=-=-" << endl;

		try {
			FalsePosition falsePosition(func, 0.00001, interv);

			cout << falsePosition.toString() << endl << endl;
			solution = falsePosition.evaluate();

			cout << "Solution:" << endl
				<< "X Approximation: " << solution.approximation[0] << endl
				<< "Y Approximation: " << solution.approximation[1] << endl << endl;
		}
		catch (exception e) {
			cout << e.what() << endl;
		}

		break;

	default:
		cout << "Invalid method" << endl;
		return 0;
	}

	return 0;
}

