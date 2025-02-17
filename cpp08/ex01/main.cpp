#include <iostream>
#include <random>
#include "Span.hpp"


std::vector<int> ranVec(int from, int to, unsigned int len) {
	std::vector<int> vec;
	vec.reserve(len);
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(from,to);
	for (unsigned int i = 0; i < len; i++)
		vec.emplace_back(distribution(generator));
	return vec;
}

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span span(0);
		span.printSpan();
	}
	{
		Span span(1000);
		std::vector<int> vec = ranVec(-100, 100, 10);
		for (int n : vec)
			span.addNumber(n);
		span.printSpan();
	}
	return 0;
}

// for range insertion, check that start is before end