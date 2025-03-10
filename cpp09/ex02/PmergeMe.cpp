#include "PmergeMe.hpp"

// Default Constructor
PmergeMe::PmergeMe () {
	std::cout << "PmergeMe: Default constructor called.\n";
}
// Parameterized Constructor
PmergeMe::PmergeMe (const std::string& name) : _name(name) {
	std::cout << "PmergeMe: Parameterized constructor called.\n"
}
// Copy Constructor
PmergeMe::PmergeMe(const PmergeMe& other) : _name(other._name) {
	std::cout << "PmergeMe: Copy constructor called.\n";
}
// Destructor
PmergeMe::~PmergeMe() {
	std::cout << "PmergeMe: Destructor called.\n";
}
// Copy Assignment Operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	std::cout << "PmergeMe: Copy assignment operator called.\n";
	if (this == &other) return *this;
	_name = other._name;
	return *this;
}
// Getters
const std::string&	PmergeMe::getName() const { return _name;}
// Setters
void	PmergeMe::setName(std::string name) { _name = name; }
// Other