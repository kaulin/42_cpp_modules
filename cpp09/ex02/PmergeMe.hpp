#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <sstream>
#include <cmath>

template <typename TContainer>
static void printContainer(TContainer cont) {
	// for (size_t i = 0; i < cont.size(); i++) {
	// 	if (i % (elementSize * 2) == 0) std::cout << "[";
	// 	std::cout << cont.at(i);
	// 	if ((i + 1) % (elementSize * 2) == 0) std::cout << "]";
	// 	else std::cout << "  ";
	// }
	for (size_t i = 0; i < cont.size(); i++) {
		std::cout << cont.at(i) << " ";
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
	static int jacobsthal(int n);
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

	template <typename TIterator>
	TIterator findBound(TIterator insert, int elementSize, TIterator lowerBound, TIterator upperBound) {
		TIterator middle;
		TIterator originalLowerBound = lowerBound;
		while (lowerBound < upperBound) {
			middle = lowerBound + std::abs(std::distance(lowerBound, upperBound)) / 2;
			middle = middle - (std::distance(originalLowerBound, middle) % elementSize);
			if (isGreater(insert, middle, elementSize))
				lowerBound = middle + elementSize;
			else
				upperBound = middle;
		}
		return lowerBound;
	}
	
	template <typename TContainer>
	void recursiveMergeInsertionSort(TContainer& cont, int depth) {
		typedef typename TContainer::iterator Iter;

		// Set up variables for recursion depth. If there are no pairs, return.
		int elementSize = std::pow(2, depth - 1);
		int elements = cont.size() / elementSize;
		int pairSize = elementSize * 2;
		int pairs = elements / 2;
		if (pairs == 0)
			return;

		// Compare and swap pairs if necessary.
		Iter it = cont.begin();
		for (int i = 0; i < pairs; i++) {
			if (isGreater(it, it + elementSize, elementSize))
				swapElements(it, elementSize);
			std::advance(it, pairSize);
		}

		// Go to the next recursion depth.
		recursiveMergeInsertionSort(cont, depth + 1);

		// Set up main and pend chains
		TContainer main, pend;
		int elementsToInsert = 0;
		it = cont.begin();
		for (int i = 0; i < elements; i++) {
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

		// Insert pend elements in ranges based on the Jacobsthal sequence
		int jIndex = 1;
		int jPrevious = 1;
		int jNumber = jacobsthal(++jIndex);
		int jDifference = jNumber - jPrevious;
		int jOffset = 0;
		int insertionRange = 0;
		int insertedThisRange = 0;
		Iter itPend, itMain;
		while (elementsToInsert) {
			if (insertedThisRange == jDifference) {
				jPrevious = jNumber;
				jNumber = jacobsthal(++jIndex);
				jDifference = jNumber - jPrevious;
				insertedThisRange = 0;
				if (elementsToInsert <= jDifference)
					jOffset = jDifference - elementsToInsert;
				insertionRange = std::pow(2, jIndex - 1) - 1 - jOffset;
			}
			itPend = pend.begin() + (jDifference - 1 - insertedThisRange - jOffset) * elementSize;
			itMain = findBound(itPend, elementSize, main.begin(), main.begin() + insertionRange * elementSize);
			main.insert(itMain, itPend, itPend + elementSize);
			insertedThisRange++;
			for (int i = 0; i < elementSize; i++)
				itPend = pend.erase(itPend);
			elementsToInsert--;
		}

		// Copy sorted elements from main to container (leftovers are not touched)
		TContainer copy(cont);
		it = cont.begin();
		for (int n : main)
			*(it++) = n;
	};
};