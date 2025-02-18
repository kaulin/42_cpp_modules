#pragma once

#include <stack>

template <typename T, typename C = std::deque<T>>
class MutantStack : public std::stack<T> {
	private:
	public:
		using iterator = typename C::iterator;
		using const_iterator = typename C::const_iterator;
		using reverse_iterator = typename C::reverse_iterator;
		using const_reverse_iterator = typename C::reverse_iterator;

		MutantStack() = default;
		MutantStack(const MutantStack& other) = default;
		MutantStack& operator=(const MutantStack& other) = default;
		~MutantStack() = default;
	
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
	
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};