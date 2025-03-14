#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>

template <typename TContainer>
static void printContainer(TContainer cont, int volume) {
	std::cout << "Volume " << volume << " after swaps: ";
	for (size_t i = 0; i < cont.size(); i++) {
		if (i % (volume * 2) == 0) std::cout << "[";
		std::cout << cont.at(i);
		if ((i + 1) % (volume * 2) == 0) std::cout << "]";
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
	void swapElements(TIterator itA, TIterator itB, int volume) {
		for (int i = 0; i < volume; i++) {
			int temp = *(itA - i);
			*(itA - i) = *(itB - i);
			*(itB - i) = temp;
		}
	};
	
	template <typename TContainer>
	void recursiveMergeInsertionSort(TContainer& cont, int volume) {
		if (cont.size() / volume < 2)
			return;
		typedef typename TContainer::iterator Ite;
		Ite it = cont.begin() + volume - 1;
		while (it + volume < cont.end()) {
			if (greater(*it, *(it + volume)))
				swapElements(it, it + volume, volume);
			std::advance(it, volume * 2);
		}
		printContainer(cont, volume);
		recursiveMergeInsertionSort(cont, volume * 2);
		
	};
};