#include "PmergeMe.hpp"

PmergeMe::PmergeMe () {}
PmergeMe::PmergeMe(const PmergeMe& other) : _comparisonCount(other._comparisonCount) {}
PmergeMe::~PmergeMe() {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other) return *this;
	_comparisonCount = other._comparisonCount;
	return *this;
}

bool PmergeMe::gT(const int a, const int b) {
	_comparisonCount++;
	return (a > b);
}

int PmergeMe::getComparisonCount() const {
	return _comparisonCount;
}

// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
// https://medium.com/@toukmati2000/cpp09-ford-johnson-algorithm-e6ad43288d4b
// https://github.com/decidedlyso/merge-insertion-sort
// https://github.com/Morwenn/cpp-sort/blob/1.x.y-stable/include/cpp-sort/detail/merge_insertion_sort.h
// https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort