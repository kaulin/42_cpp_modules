#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>

class PmergeMe {
public:
	PmergeMe();
	~PmergeMe();
	
	void sortVector(std::vector<int>& vector);
	void sortDeque(std::deque<int>& deque);
	int getComparisonCount() const;
private:
	int _comparisonCount;
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	
	bool greater(const int a, const int b);
	static int isOdd(int n);
	
	template <typename Tcontainer>
	void recursiveMergeInsertionSort(Tcontainer& cont, int volume) {
		typedef typename Tcontainer::iterator Iterator;
		(void)volume;
	
		Iterator it = cont.begin();
		if (greater(*it, *(it + 1))) {
			int temp = *it;
			*it = *(it + 1);
			*(it + 1) = temp;
		}
	};
};