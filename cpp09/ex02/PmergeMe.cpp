#include "PmergeMe.hpp"

PmergeMe::PmergeMe () {}
PmergeMe::PmergeMe (const std::string& name) : _name(name) {}
PmergeMe::PmergeMe(const PmergeMe& other) : _name(other._name) {}
PmergeMe::~PmergeMe() {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other) return *this;
	_name = other._name;
	return *this;
}

// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91