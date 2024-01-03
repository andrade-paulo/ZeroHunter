#ifndef Interval_H
#define Interval_H
#include <string>

class Interval {
private:
	double start;
	double end;

public:
	// Constructor
	Interval(double start, double end);

	// Get
	double getStart();

	double getEnd();

	// toString
	std::string toString();
};

#endif