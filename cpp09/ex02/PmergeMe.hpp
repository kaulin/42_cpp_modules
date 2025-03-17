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
	static int isOdd(int n);

	template <typename TIterator>
	bool isGreater(const TIterator a, const TIterator b, int elementSize) {
		_comparisonCount++;
		return *(a + elementSize - 1) > *(b + elementSize - 1);
	}
	
	template <typename TIterator>
	void swapElements(TIterator it, int elementSize) {
		for (int i = 0; i < elementSize; i++) {
			int temp = *(it + i);
			*(it + i) = *(it + elementSize + i);
			*(it + elementSize + i) = temp;
		}
	};

	// template <typename TIterator, typename TContainer>
	// TIterator findPlace(int elementValue, int elementSize, TIterator lowerBound, TIterator upperBound) {

	// }
	
	template <typename TContainer>
	void recursiveMergeInsertionSort(TContainer& cont, int depth) {
		typedef typename TContainer::iterator Iter;

		// Set up variables for depth
		int elementSize = std::pow(2, depth - 1);
		int pairSize = elementSize * 2;
		int elements = cont.size() / elementSize;
		// int leftovers = cont.size() - elements * elementSize;

		// Compare and swap pairs if necessary.
		Iter it = cont.begin();
		while (it + pairSize -1 < cont.end()) {
			if (isGreater(it, it + elementSize, elementSize))
				swapElements(it, elementSize);
			std::advance(it, pairSize);
		}

		printContainer(cont, depth, elementSize);
		// Head deeper if pairs exist on the next depth.
		if (elements >= 4)
			recursiveMergeInsertionSort(cont, depth + 1);
		// Nothing further to do for less than 3 elements.
		if (elements < 3)
			return;
		
		// Set up main and pend chains and helper variables
		TContainer main, pend;
		int elementsToInsert = 0;
		int elementsInserted = 0;
		it = cont.begin();
		for (int i = 0; i * elementSize < elements; i++) {
			// main chain = b1, a1, ..., an
			if (i == 0 || isOdd(i))
				main.insert(main.end(), it, it + elementSize);
			// pend chain = b2, ..., bn
			else {
				pend.insert(pend.end(), it, it + elementSize);
				elementsToInsert++;
			}
			std::advance(it, elementSize);
		}

//		Iter dest, lowerBound, upperBound;
		while (elementsToInsert) {
			// Select pend element to insert into main using Jabobstahl
			it = pend.begin();
			elementsInserted++;
			elementsToInsert--;
			// Insert pend element to main, remove from pend
			
		}

		// Add leftover elements to the end of main
		while (it != cont.end())
			main.emplace_back(*(it++));
		
		// Copy elements from main back to container
		TContainer copy(cont);
		it = cont.begin();
		for (int n : main)
			*(it++) = n;
	};
};