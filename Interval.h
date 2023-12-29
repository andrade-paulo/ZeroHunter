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

	// Getters and Setters
	double getStart();
	
	double getEnd();
	
	void setStart(double start);
	
	void setEnd(double end);

	// toString
	std::string toString();
};

#endif