#pragma once

#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>

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
		//void import(std::iterator& start, std::iterator& end); TODO
};