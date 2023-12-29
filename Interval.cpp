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

double Interval::getStart() {
	return start;
}

double Interval::getEnd() {
	return end;
}

void Interval::setStart(double start) {
	this->start = start;
}

void Interval::setEnd(double end) {
	this->end = end;
}

std::string Interval::toString() {
	return "[" + std::to_string(start) + ", " + std::to_string(end) + "]";
}