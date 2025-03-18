#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include "PmergeMe.hpp"

// Returns the max number of comparisons for n elements, courtesy of https://github.com/emuminov
static int worstCase(int n) {
	int result = 0;
	for (int i = 1; i <= n; ++i) {
		double value = (3.0 / 4.0) * i;
		result += static_cast<int>(ceil(log2(value)));
	}
	return result;
}

static void isIntString(const std::string& string) {
	try {
		if (string.empty() || string.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("invalid argument: " + string);
		std::stoi(string);
	} catch (const std::out_of_range& e) {
		throw std::invalid_argument("invalid argument: " + string);
	}
}

static void validateArgs(int argc, char **argv) {
	for (int i = 1; i < argc; i++)
		isIntString(argv[i]);
}

static void printBefore(int argc, char** argv) {
	std::stringstream sstream;
	sstream << "Before: ";
	for (int i = 1; i < argc; i++)
		sstream << argv[i] << " ";
	std::cout << sstream.str() << "\n";
}

static void printAfter(std::vector<int> vec) {
	std::stringstream sstream;
	sstream << "After: ";
	for (int n : vec)
		sstream << n << " ";
	std::cout << sstream.str() << "\n";
}

static std::vector<int> argsToVector(int argc, char** argv) {
	std::vector<int> vec;
	vec.reserve(argc - 1);
	for (int i = 1; i < argc; i++)
		vec.emplace_back(std::atoi(argv[i]));
	return vec;
}

static std::deque<int> argsToDeque(int argc, char** argv) {
	std::deque<int> deq;
	for (int i = 1; i < argc; i++)
		deq.emplace_back(std::atoi(argv[i]));
	return deq;
}

static std::set<int> argsToSet(int argc, char** argv) {
	std::set<int> set;
	for (int i = 1; i < argc; i++) {
		if (set.insert(std::atoi(argv[i])).second == false)
			throw std::invalid_argument("duplicate integer: " + std::string(argv[i]));
	}
	return set;
}

template <typename TcontainerA, typename TcontainerB>
static bool compareContainers(TcontainerA a, TcontainerB b) {
	if (a.size() != b.size())
		return false;
	typedef typename TcontainerA::iterator IteratorA;
	typedef typename TcontainerB::iterator IteratorB;
	IteratorA itA = a.begin();
	IteratorB itB = b.begin();
	while (itA != a.end() && itB != b.end()) {
		if (*itA != *itB)
			return false;
		std::advance(itA, 1);
		std::advance(itB, 1);
	}
	return true;
}

int main(int argc, char** argv) {
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " positive_integer1 positive_integer2 [positive_integer3] ... [positive_integerN]\n";
		return 1;
	}
	std::set<int> results;
	try {
		validateArgs(argc, argv);
		results = argsToSet(argc, argv);
	} catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << "\n";
		return -1;
	}

	// Vector test
	clock_t vecStart = clock();
	PmergeMe sorterVec;
	std::vector<int> vec = argsToVector(argc, argv);
	sorterVec.sortVector(vec);
	time_t vecStop = clock();
	if (!compareContainers(results, vec))
		std::cout << "Vector sort incorrect!\n";
	double vecDuration = static_cast<double>(vecStop - vecStart) / CLOCKS_PER_SEC;
	
	// Deque test
	clock_t deqStart = clock();
	PmergeMe sorterDeq;
	std::deque<int> deq = argsToDeque(argc, argv);
	sorterDeq.sortDeque(deq);
	time_t deqStop = clock();
	if (!compareContainers(results, deq))
		std::cout << "Deq sort incorrect!\n";
	double deqDuration = static_cast<double>(deqStop - deqStart) / CLOCKS_PER_SEC;

	// validate results

	printBefore(argc, argv);
	printAfter(vec);
	// std::cout << "Time to process a range of " << argc -1 << " elements with std::vector : " << vecDuration * 1000 << " us\n";
	// std::cout << "Time to process a range of " << argc -1 << " elements with std::deque : " << deqDuration * 1000 << " us\n";
	std::cout << "Vector - elements: " << argc -1 << ", comparisons: " << sorterVec.getComparisonCount() << "/" << worstCase(argc) << ", time: " << vecDuration * 1000 << " us\n";
	std::cout << "Deque - elements: " << argc -1 << ", comparisons: " << sorterDeq.getComparisonCount() << "/" << worstCase(argc) << ", time: " << deqDuration * 1000 << " us\n";
	
	return 0;
}