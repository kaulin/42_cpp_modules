#include <iostream>
#include <list>
#include "MutantStack.hpp"

void subjectTest() {
	{
		std::cout << "Testing MutantStack using example from subject\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\nSame operations using a list\n";
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
}

int main(int argc, char** argv) {
	if (argc < 2) {
		subjectTest();
	}
	else {
		std::cout << "Testing MutantStack using argument array\n";
		MutantStack<std::string> mstack;
		for (int i = 1; i < argc; i++) {
			mstack.push(argv[i]);
		}

		std::cout << "\nTesting iterators:\n";
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << "\nTesting reverse iterators:\n";
		MutantStack<std::string>::reverse_iterator rit = mstack.rbegin();
		MutantStack<std::string>::reverse_iterator rite = mstack.rend();
		while (rit != rite) {
			std::cout << *rit << std::endl;
			++rit;
		}

		std::cout << "\nRemoves \"" << mstack.top() << "\"";
		mstack.pop();
		mstack.push("Hello World!");
		std::cout << " and adds \"" << mstack.top() << "\"\n";
		std::cout << "Testing constant iterators:\n";
		MutantStack<std::string>::const_iterator cit = mstack.begin();
		MutantStack<std::string>::const_iterator cite = mstack.end();
		while (cit != cite) {
			std::cout << *cit << std::endl;
			++cit;
		}

		std::cout << "\nTesting constant reverse iterators:\n";
		MutantStack<std::string>::const_reverse_iterator crit = mstack.rbegin();
		MutantStack<std::string>::const_reverse_iterator crite = mstack.rend();
		while (crit != crite) {
			std::cout << *crit << std::endl;
			++crit;
		}
	}
	return 0;
}