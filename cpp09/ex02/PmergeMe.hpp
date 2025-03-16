#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <cmath>

template <typename TContainer>
static void printContainer(TContainer cont, int depth, int elementSize) {
	std::cout << "Recursion depth " << depth << ", elementSize " << elementSize << ":\n";
	for (size_t i = 0; i < cont.size(); i++) {
		if (i % (elementSize * 2) == 0) std::cout << "[";
		std::cout << cont.at(i);
		if ((i + 1) % (elementSize * 2) == 0) std::cout << "]";
		else std::cout << "  ";
	}
	std::cout << "\n";
}

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
	
	template <typename TIterator>
	void addElementToVector(TIterator it, int elementSize, std::vector<int>& vec) {
		for (int i = 0; i < elementSize; i++)
			vec.emplace_back(*(it + i));
	}
	
	template <typename TIterator>
	void swapElements(TIterator itA, TIterator itB, int elementSize) {
		for (int i = 0; i < elementSize; i++) {
			int temp = *(itA - i);
			*(itA - i) = *(itB - i);
			*(itB - i) = temp;
		}
	};
	
	template <typename TContainer>
	void recursiveMergeInsertionSort(TContainer& cont, int depth) {

		// Set up variables for depth
		int elementSize = std::pow(2, depth - 1);
		int pairSize = elementSize * 2;
		int elements = cont.size() / elementSize;
		// int leftovers = cont.size() - elements * elementSize;

		// Compare and swap pairs if necessary.
		typename TContainer::iterator it = cont.begin() + elementSize - 1;
		while (it + elementSize < cont.end()) {
			if (greater(*it, *(it + elementSize)))
				swapElements(it, it + elementSize, elementSize);
			std::advance(it, pairSize);
		}

		printContainer(cont, depth, elementSize);
		// Head deeper if pairs exist on the next depth.
		if (elements > 3)
			recursiveMergeInsertionSort(cont, pairSize);
		// Nothing further to do for less than 3 elements.
		if (elements < 3)
			return;
		
		// Set up main and pend chains
		std::vector<int> main, pend;
		main.reserve(cont.size());
		it = cont.begin();
		for (int i = 0; i * elementSize < elements; i++) {
			// main chain = b1, a1, a2 ... an
			if (i == 0 || isOdd(i))
				addElementToVector(it, elementSize, main);
			// pend chain = b2 ... bn
			else
				addElementToVector(it, elementSize, pend);
			std::advance(it, elementSize);
		}

		// select pend element to insert into main using Jabobstahl
		// insert pend element to main, remove from pend
		// repeat till pend empty

		// add leftover elements to the end of main
		while (it != cont.end())
			main.emplace_back(*(it++));
		
		// copy sorted elements from main back to container
		TContainer copy(cont);
		it = cont.begin();
		for (int n : main)
			*(it++) = n;
	};
};