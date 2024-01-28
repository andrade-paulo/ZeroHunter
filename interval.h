#pragma once

#include <string>

class Interval {
private:
	double start;
	double end;

public:
	// Constructor
	Interval(double start, double end);
	Interval();

	// Get
	double getStart();
	
	double getEnd();

	// toString
	std::string toString();
};
