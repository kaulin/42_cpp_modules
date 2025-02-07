#include "Span.hpp"

Span::Span() {}
Span::Span(unsigned int max) : _max(max) {}
Span::~Span() {}
Span::Span(const Span& other) : _max(other._max) {
	if (!other._ints.empty()) {
		for (int n : other._ints)
			_ints.insert(n);
	}
}
Span Span::operator=(const Span& other) {
	if (this == &other)
		return *this;
	_max = other._max;
	if (!other._ints.empty()) {
		for (int n : other._ints)
			_ints.insert(n);
	}
}
void Span::addNumber(int num) {}
int Span::shortestSpan() const {}
int Span::longestSpan() const {}