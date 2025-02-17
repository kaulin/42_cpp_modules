#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int max) : _max(max) {}

Span::~Span() {}

Span::Span(const Span& other) : _max(other._max), _ints(other._ints) {}

Span Span::operator=(const Span& other) {
	if (this != &other) {
		_max = other._max;
		_ints = other._ints;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_ints.size() >= _max)
		throw std::runtime_error("span is out of space");
	_ints.insert(n);
}

void Span::addNumbers(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last) {
	if (first >= last)
		throw std::runtime_error("problematic iterators");
}

int Span::shortestSpan() const {
	if (_ints.size() < 2)
		throw std::runtime_error("span impossible");
	std::vector<int> spans(_ints.size() -1 );
	std::adjacent_difference(_ints.begin(), _ints.end(), spans.begin());
	return *std::min_element(spans.begin() + 1, spans.end());
}

int Span::longestSpan() const {
	if (_ints.size() < 2)
		throw std::runtime_error("span impossible");
	return std::abs(*_ints.begin() - *_ints.rbegin());
}

void Span::printSpan() const {
	std::cout << "Span of size " << _max << " contains " << _ints.size() << " elements:\n";
	for (std::multiset<int>::iterator it = _ints.begin(); it != _ints.end(); it++)
		std::cout << *it << (std::next(it) != _ints.end() ? " " : "\n");
	try {
		std::cout << "Shortest span: " << shortestSpan() << "\n";
	} catch(std::runtime_error e) {
		std::cout << e.what() << "\n";
	}
	try {
		std::cout << "Longest span: " << longestSpan() << "\n";
	} catch(std::runtime_error e) {
		std::cout << e.what() << "\n";
	}
}