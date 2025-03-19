#pragma once

#include <iostream>
#include <vector>
#include <deque>
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
	TIterator upperBound(TIterator insert, int elementSize, TIterator lowerBound, TIterator upperBound) {
		TIterator middle;
		TIterator originalLowerBound = lowerBound;
		std::cout << "Looking for bound for " << *(insert + elementSize - 1) << ", initial bound " << *(upperBound + elementSize - 1);
		while (lowerBound < upperBound) {
			middle = lowerBound + std::abs(std::distance(lowerBound, upperBound)) / 2;
			middle = middle - (std::distance(originalLowerBound, middle) % elementSize);
			if (isGreater(insert, middle, elementSize))
				lowerBound = middle + elementSize;
			else
				upperBound = middle;
		}
		std::cout << ", final bound " << *(lowerBound + elementSize - 1) << "\n";
		return lowerBound;
	}
	
	template <typename TContainer>
	void recursiveMergeInsertionSort(TContainer& cont, int depth) {
		typedef typename TContainer::iterator Iter;
		// std::cout << "\nEntered recursion depth " << depth << "\n";

		// Set up variables for depth
		int elementSize = std::pow(2, depth - 1);
		int pairSize = elementSize * 2;
		int elements = cont.size() / elementSize;
		if (elements < 2)
			return;

		// Compare and swap pairs if necessary.
		Iter it = cont.begin();
		while (it + pairSize - 1 < cont.end()) {
			if (isGreater(it, it + elementSize, elementSize))
				swapElements(it, elementSize);
			std::advance(it, pairSize);
		}

		recursiveMergeInsertionSort(cont, depth + 1);
		// std::cout << "\nReturned to recursion depth " << depth << " with\n";
		// printContainer(cont);
		
		// Set up main and pend chains and helper variables
		TContainer main, pend;
		int elementsToInsert = 0;
		int elementsInserted = 1; // b1 automatically inserted
		bool oddFlag = isOdd(elements) ? true : false;
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

		// Calculate range of insertions based on the j[acobsthal] sequence
		int jIndex = 1;
		int jPrevious = 1;
		int jNumber = jacobsthal(++jIndex);
		int jDiff = jNumber - jPrevious;
		int jOffset = 0;
		int insertionRange = 0;
		int boundOffset = 0;
		int inserted = 0;
		Iter itPend, itMain, itMainUpperBound;
		int pendIndex;
		bool lastFlag = false;
		while (elementsToInsert) {
			if (inserted == jDiff) {
				jPrevious = jNumber;
				jNumber = jacobsthal(++jIndex);
				jDiff = jNumber - jPrevious;
				inserted = 0;
				boundOffset = 0;
				if (elementsToInsert <= jDiff) {
					jOffset = jDiff - elementsToInsert;
					lastFlag = true;
					// std::cout << "Last cycle of depth " << depth << ": offset " << jOffset << " and" << (oddFlag ? " odd element " : " no odd element") << "\n";
				}
				insertionRange = std::pow(2, jIndex - 1) - 1 - jOffset;
				// std::cout << "Moving to next Jacobsthal number: jNum " << jNumber << " jPrev " << jPrevious << ", jDiff " << jDiff << ", insertionRange " << insertionRange << ", elementsInserted " << elementsInserted << ", leftToInsert " << elementsToInsert << "\n";
			}
			// std::cout << "Main: ";
			// printContainer(main);
			// std::cout << "Pend: ";
			// printContainer(pend);
			pendIndex = jDiff - 1 - inserted - jOffset;
			itPend = pend.begin() + pendIndex * elementSize;
			itMain = main.begin() + (insertionRange + boundOffset) * elementSize;
			if (oddFlag && lastFlag) {
				// itMain += elementSize;
				lastFlag = false;
			}
			itMainUpperBound = upperBound(itPend, elementSize, main.begin(), itMain);
			if (itMainUpperBound >= itMain) // b element is inserted right next to corresponding a, next 
				boundOffset++;
			main.insert(itMainUpperBound, itPend, itPend + elementSize);
			inserted++;
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
	};
};