#pragma once

#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span {
	private:
		unsigned int _max;
		std::multiset<int> _ints;
		Span();
	public:
		Span(unsigned int max);
		~Span();
		Span(const Span& other);
		Span operator=(const Span& other);
		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;
		void addNumbers(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);
		void printSpan() const;
};