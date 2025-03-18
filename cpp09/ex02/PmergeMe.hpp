#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <cmath>

template <typename TContainer>
static void printContainer(TContainer cont, int depth, int elementSize) {
	std::cout << "recursion depth " << depth << ", elementSize " << elementSize << ":\n";
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
	TIterator upperBound(TIterator insert, int elementSize, TIterator lowerBound, TIterator upperBound) {
		TIterator middle;
		while (lowerBound < upperBound) {
			middle = lowerBound + std::abs(std::distance(lowerBound, upperBound)) / 2;
			if (isGreater(insert, middle, elementSize))
				lowerBound = middle + 1;
			else
				upperBound = middle;
		}
		return lowerBound;
	}
	
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

		//printContainer(cont, depth, elementSize);
		// Head deeper if pairs exist on the next depth.
		if (elements >= 4)
			recursiveMergeInsertionSort(cont, depth + 1);
		// Nothing further to do for less than 3 elements.
		if (elements < 3)
			return;
		
		// Set up main and pend chains and helper variables
		TContainer main, pend;
		int elementsToInsert = 0;
		int elementsInserted = 1; // b1 automatically inserted
		int oddFlag = isOdd(elements) ? 1 : 0;
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

		// Calculate range of insertions based on the j[acobsthal] sequence
		int jIndex = 1;
		int jPrevious = 1;
		int jNumber = jacobsthal(++jIndex);
		int jOffset = 0;
		int lastFlag = 0;
		Iter itPend, itMain;
		while (elementsToInsert) {
			if (jNumber == elementsInserted) {
				jPrevious = jNumber;
				jNumber = jacobsthal(++jIndex);
				if (elementsToInsert <= jNumber - jPrevious) {
					jOffset = jNumber - jPrevious - elementsToInsert;
					lastFlag = 1;
				}
				std::cout << "Moving to next Jacobsthal number: jNum " << jNumber << " jPrev " << jPrevious << ", jDiff " << jNumber - jPrevious << ", inserted " << elementsInserted << "\n";
			}
			std::cout << "Main before: ";
			printContainer(main, depth, elementSize);
			std::cout << "Pend before: ";
			printContainer(pend, depth, elementSize);
			itPend = pend.begin() + (jNumber - elementsInserted - jPrevious - jOffset) * elementSize;
			itMain = upperBound(itPend, elementSize, main.begin(), main.begin() + (jNumber + elementsInserted - jOffset + oddFlag * lastFlag--) * elementSize);
			std::cout << "Inserting " << *itPend + elementSize - 1 << " before " << *itMain + elementSize - 1 << "\n";
			for (int i = 0; i < elementSize; i++)
				itMain = main.insert(itMain, itPend, itPend + elementSize);
			elementsInserted++;
			for (int i = 0; i < elementSize; i++)
				itPend = pend.erase(itPend);
			elementsToInsert--;
		}
		
		// Copy elements from main back to container
		TContainer copy(cont);
		it = cont.begin();
		for (int n : main)
			*(it++) = n;
		std::cout << "Cont: ";
		printContainer(cont, depth, elementSize);
	};
};