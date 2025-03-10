#include "RPN.hpp"

// Default Constructor
RPN::RPN () {
	std::cout << "RPN: Default constructor called.\n";
}
// Parameterized Constructor
RPN::RPN (const std::string& name) : _name(name) {
	std::cout << "RPN: Parameterized constructor called.\n"
}
// Copy Constructor
RPN::RPN(const RPN& other) : _name(other._name) {
	std::cout << "RPN: Copy constructor called.\n";
}
// Destructor
RPN::~RPN() {
	std::cout << "RPN: Destructor called.\n";
}
// Copy Assignment Operator
RPN& RPN::operator=(const RPN& other) {
	std::cout << "RPN: Copy assignment operator called.\n";
	if (this == &other) return *this;
	_name = other._name;
	return *this;
}
// Getters
const std::string&	RPN::getName() const { return _name;}
// Setters
void	RPN::setName(std::string name) { _name = name; }
// Other