#include "zeroHunter.h"
using namespace std;

int main() {

		Function func;
		double a, b, errorMargin, initialPoint;
		char method;
		bool exit;

		do {
				cout << "-=-=- ZeroHunter -=-=-" << endl;

				cout << "Error margin: ";
				cin >> errorMargin;

				cout << endl;

				cout << "Choose method" << endl
						<< "1. Bisection" << endl
						<< "2. False Position" << endl
						<< "3. Fixed Point" << endl
						<< "4. Newton Method" << endl
						<< "5. Secant Method" << endl
						<< ": ";
				cin >> method;

				cout << endl << endl;

				Solution solution;

				switch (method) {
						case '1': {
								cout << "-=-=- Bisection method -=-=-" << endl;

								cout << "Initial interval: ";
								cin >> a >> b;
								Interval interv(a, b);

								cout << endl;

								try {
										Bisection bisection(func, errorMargin, interv);

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
						}

						case '2': {
								cout << "-=-=- False Position method -=-=-" << endl;

								cout << "Initial interval: ";
								cin >> a >> b;
								Interval interv(a, b);

								cout << endl;

								try {
										FalsePosition falsePosition(func, errorMargin, interv);

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
						}

						case '3': {
								cout << "-=-=- Fixed Point method -=-=-" << endl;

								cout << "Initial point: ";
								cin >> initialPoint;

								cout << endl;

								try {
										FixedPoint fixedPoint(func, func, errorMargin, initialPoint, 30);

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

						}

						case '4': {
								cout << "-=-=- Newton Method -=-=-" << endl;

								cout << "Initial point: ";
								cin >> initialPoint;

								cout << endl;

								try {
										NewtonMethod newtonMethod(func, func, errorMargin, initialPoint, 30);

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

						}

						case '5': {
								cout << "-=-=- Secant method -=-=-" << endl;

								cout << "Initial points: ";
								cin >> a >> b;

								double points[2] = {a, b};

								cout << endl;

								try {
										SecantMethod secantMethod(func, func, errorMargin, points, 30);

										cout << secantMethod.toString() << endl << endl;
										solution = secantMethod.evaluate();

										cout << "Solution:" << endl
												<< "X Approximation: " << solution.approximation[0] << endl
												<< "Y Approximation: " << solution.approximation[1] << endl << endl;
								}
								catch (const runtime_error& e) {
										cout << e.what() << endl;
								}

								break;

						}

						default: {
								cout << "Invalid method" << endl;
								return 0;
						}
				}

				cout << "Do you want to exit? (0/1): ";
				cin >> exit;
				cout << endl;
		} while (!exit);

		return 0;
}

