#include "PmergeMe.hpp"

PmergeMe::PmergeMe () : _comparisonCount(0) {}
PmergeMe::PmergeMe(const PmergeMe& other) : _comparisonCount(other._comparisonCount) {}
PmergeMe::~PmergeMe() {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other) return *this;
	_comparisonCount = other._comparisonCount;
	return *this;
}

void PmergeMe::sortVector(std::vector<int>& vec) {
	_comparisonCount = 0;
	recursiveMergeInsertionSort<std::vector<int>>(vec, 1);
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
	_comparisonCount = 0;
	recursiveMergeInsertionSort<std::deque<int>>(deq, 1);
}

int PmergeMe::getComparisonCount() const {
	return _comparisonCount;
}

int PmergeMe::jacobsthal(int n) {
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	int temp;
	int prev = 0;
	int result = 1;
	for (int i = 1; i < n; i++) {
		temp = result;
		result = prev * 2 + result;
		prev = temp;
	}
	return result;
}

int PmergeMe::isOdd(int n) {
	return n & 1;
}