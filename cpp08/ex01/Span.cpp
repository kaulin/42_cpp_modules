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
	if (this != &other) {
		_max = other._max;
		if (!other._ints.empty()) {
			for (int n : other._ints)
				_ints.insert(n);
		}
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_ints.size() >= _max)
		throw std::runtime_error("span is out of space");
	_ints.insert(n);
}

int Span::shortestSpan() const {
	if (_ints.size() < 2)
		throw std::runtime_error("span impossible");
	std::vector<int> spans;
	std::adjacent_difference(_ints.begin(), _ints.end(), spans.begin());
	return *std::min_element(++spans.begin(), spans.end());
}

int Span::longestSpan() const {
	if (_ints.size() < 2)
		throw std::runtime_error("span impossible");
	return *_ints.begin() - *_ints.rbegin();
}