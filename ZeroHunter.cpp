#include "ZeroHunter.h"
using namespace std;

int main() {
	// Bisection test
	Interval interv(-4, 2);

	cout << "-=-=- Bisection method -=-=-" << endl;
	try {
		double aproximation = bisectionMethod(interv, 0.0001);
		cout << "Aproximation: " << aproximation << endl;

		cout << "Function value: " << function(aproximation) << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	cout << endl << endl;

	cout << "-=-=- False Position method -=-=-" << endl;
	try {
		double aproximation = falsePositionMethod(interv, 0.0001);
		cout << "Aproximation: " << aproximation << endl;

		cout << "Function value: " << function(aproximation) << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	return 0;
}

