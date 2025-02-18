#include <iostream>
#include <random>
#include "Span.hpp"

// Note: use of uniform_int_distribution causes high likelihood of values close to range extremes to always appear in sets
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
		std::cout << "Subject test\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.printSpan();
	}
	{
		std::cout << "\nTestig span of 0\n";
		Span span(0);
		span.printSpan();
		std::cout << "Adding a number, but max capacity reached:\n";
		try {
			span.addNumber(42);
		} catch (std::runtime_error e) {
			std::cout << "Caught error: " << e.what() << "\n";
		}
	}
	{
		std::cout << "\nTesting span of 1\n";
		Span span(1);
		span.addNumber(42);
		span.printSpan();
		std::cout << "Adding a number, but max capacity reached:\n";
		try {
			span.addNumber(42);
		} catch (std::runtime_error e) {
			std::cout << "Caught error: " << e.what() << "\n";
		}
	}
	{
		std::cout << "\nTesting span of 6 with range insertion\n";
		Span span(6);
		std::vector<int> vec = {0, 1, 2, 3, 4};
		span.addNumbers(vec.begin(), vec.end());
		span.printSpan();
		vec.emplace_back(5);
		vec.emplace_back(6);
		try {
			span.addNumbers(vec.begin() + 5, vec.end());
		} catch (std::runtime_error e) {
			std::cout << "Caught error: " << e.what() << "\n";
		}
		span.printSpan();
		std::cout << "Adding range, but end iterator is before begin:\n";
		try {
			span.addNumbers(vec.end(), vec.begin());
		} catch (std::runtime_error e) {
			std::cout << "Caught error: " << e.what() << "\n";
		}
		std::cout << "Adding range, but end iterator is same as begin:\n";
		try {
			span.addNumbers(vec.end(), vec.end());
		} catch (std::runtime_error e) {
			std::cout << "Caught error: " << e.what() << "\n";
		}
	}
	{
		std::cout << "\nTesting span of 1000 with range insertion of random integers\n";
		Span span(1000);
		std::vector<int> vec = ranVec(-2147483648, 2147483647, 10);
		span.addNumbers(vec.begin(), vec.end());
		span.printSpan();
		std::vector<int> vec2 = ranVec(-2147483648, 2147483647, 1000);
		try {
			span.addNumbers(vec2.begin(), vec2.end());
		} catch (std::runtime_error e) {
			std::cout << "Caught error: " << e.what() << "\n";
		}
		span.printSpan();
	}
	{
		std::cout << "\nTesting span of 10000 with range insertion of random integers\n";
		Span span(10000);
		std::vector<int> vec = ranVec(-2147483648, 2147483647, 10000);
		span.addNumbers(vec.begin(), vec.end());
		span.printSpan();
	}
	{
		std::cout << "\nTesting span of 1000000 with range insertion of random integers\n";
		Span span(1000000);
		std::vector<int> vec = ranVec(-2147483648, 2147483647, 1000000);
		span.addNumbers(vec.begin(), vec.end());
		span.printSpan();
	}
	{
		std::cout << "\nTesting span of 10000000 with range insertion of random integers\n";
		Span span(10000000);
		std::vector<int> vec = ranVec(-2147483648, 2147483647, 10000000);
		span.addNumbers(vec.begin(), vec.end());
		span.printSpan();
	}
	return 0;
}