#include "MyClass.hpp"

// Default Constructor
MyClass::MyClass () {
	std::cout << "MyClass: Default constructor called.\n";
}
// Parameterized Constructor
MyClass::MyClass (const std::string& name) : _name(name) {
	std::cout << "MyClass: Parameterized constructor called.\n"
}
// Copy Constructor
MyClass::MyClass(const MyClass& other) : _name(other._name) {
	std::cout << "MyClass: Copy constructor called.\n";
}
// Destructor
MyClass::~MyClass() {
	std::cout << "MyClass: Destructor called.\n";
}
// Copy Assignment Operator
MyClass& MyClass::operator=(const MyClass& other) {
	std::cout << "MyClass: Copy assignment operator called.\n";
	if (this == &other) return *this;
	_name = other._name;
	return *this;
}
// Getters
const std::string&	MyClass::getName() const { return _name;}
// Setters
void	MyClass::setName(std::string name) { _name = name; }
// Other