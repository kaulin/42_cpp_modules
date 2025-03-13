#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe {
private:
	int _comparisonCount;
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	
	bool gT(const int a, const int b);
public:
	PmergeMe();
	~PmergeMe();

	void sortVector(std::vector<int>& vector);
	void sortDeque(std::deque<int>& deque);
	int getComparisonCount() const;
};