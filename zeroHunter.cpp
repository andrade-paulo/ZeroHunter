#include "zeroHunter.h"
using namespace std;

int main() {

	Function func;
	double a, b, errorMargin, initialPoint;
	char method;
	bool exit;

	do {
		cout << "-=-=- ZeroHunter -=-=-" << endl;

		cout << "Initial interval: ";
		cin >> a >> b;

        cout << "Initial point: ";
        cin >> initialPoint;

		Interval interv(a, b);

		cout << endl;

		cout << "Error margin: ";
		cin >> errorMargin;

		cout << endl;

		cout << "Choose method" << endl
			<< "1. Bisection" << endl
			<< "2. False Position" << endl
			<< "3. Fixed Point" << endl
			<< "4. Newton Method" << endl
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
			catch (const runtime_error& e) {
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
			catch (const runtime_error& e) {
				cout << e.what() << endl;
			}

			break;

        case '3':
            cout << "-=-=- Fixed Point method -=-=-" << endl;

			try {
				FixedPoint fixedPoint(func, func, 0.00001, initialPoint, 30);

				cout << fixedPoint.toString() << endl << endl;
				Solution solution = fixedPoint.evaluate();

				cout << "Solution:" << endl
					<< "X Approximation: " << solution.approximation[0] << endl
					<< "Y Approximation: " << solution.approximation[1] << endl << endl;
			}
			catch (const runtime_error& e) {
				cout << e.what() << endl;
			}

			break;

		case '4':
            cout << "-=-=- Newton Method -=-=-" << endl;

			try {
				NewtonMethod newtonMethod(func, func, 0.00001, initialPoint, 30);

				cout << newtonMethod.toString() << endl << endl;
				Solution solution = newtonMethod.evaluate();

				cout << "Solution:" << endl
					<< "X Approximation: " << solution.approximation[0] << endl
					<< "Y Approximation: " << solution.approximation[1] << endl << endl;
			}
			catch (const runtime_error& e) {
				cout << e.what() << endl;
			}

			break;

		default:
			cout << "Invalid method" << endl;
			return 0;
		}

		cout << "Do you want to exit? (0/1): ";
		cin >> exit;
		cout << endl;
	} while (!exit);

	return 0;
}

