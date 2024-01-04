#include "Interval.h"

// Methods implementation
Interval::Interval(double start, double end) {
	if (start < end) {
		this->start = start;
		this->end = end;
	}
	else {
		this->start = end;
		this->end = start;
	}
}

Interval::Interval() {
	this->start = 0;
	this->end = 0;
}

double Interval::getStart() {
	return this->start;
}

double Interval::getEnd() {
	return this->end;
}

std::string Interval::toString() {
	return "[" + std::to_string(start) + ", " + std::to_string(end) + "]";
}