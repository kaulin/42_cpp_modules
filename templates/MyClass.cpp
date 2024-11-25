#include "MyClass.hpp"

// Default Constructor
MyClass::MyClass () {
	std::cout << "Default constructor called." << std::endl;
}
// Parameterized Constructor
MyClass::MyClass (const std::string& name) : _name(name) {
	std::cout << "Parameterized constructor called." << std::endl;
}
// Copy Constructor
MyClass::MyClass(const MyClass& other) : _name(other._name) {
	std::cout << "Copy constructor called." << std::endl;
}
// Destructor
MyClass::~MyClass() {
	std::cout << "Destructor called." << std::endl;
}
// Copy Assignment Operator
MyClass& MyClass::operator=(const MyClass& other) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	_name = other._name;
	return *this;
}
// Getters
const std::string&	MyClass::getName() const { return _name;}
// Setters
void	MyClass::setName(std::string name) { _name = name; }
// Other