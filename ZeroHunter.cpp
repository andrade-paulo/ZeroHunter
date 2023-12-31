#include "ZeroHunter.h"
using namespace std;

int main() {
	// Bisection test
	Interval interv(-4, 2);

	double aproximation;

	Function func;

	cout << "-=-=- Bisection method -=-=-" << endl;
	try {
		aproximation = bisectionMethod(interv, 0.00001);
		cout << "Aproximation: " << aproximation << endl;

		cout << "Function value: " << func.evaluate(aproximation) << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	cout << endl << endl;

	cout << "-=-=- False Position method -=-=-" << endl;
	try {
		aproximation = falsePositionMethod(interv, 0.00001);
		cout << "Aproximation: " << aproximation << endl;

		cout << "Function value: " << func.evaluate(aproximation) << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	return 0;
}

