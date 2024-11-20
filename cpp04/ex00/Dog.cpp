#include "Dog.hpp"

// Default Constructor
Dog::Dog () : _type("Undefined dog") {
	std::cout << "	Dog: Default constructor called." << std::endl;
}
// Parameterized Constructor
Dog::Dog (const std::string& name) : _type(name) {
	std::cout << "	Dog: Parameterized constructor called." << std::endl;
}
// Destructor
Dog::~Dog() {
	std::cout << "	Dog: Destructor called." << std::endl;
}
// Copy Constructor
Dog::Dog(const Dog& other) : _type(other._type) {
	std::cout << "	Dog: Copy constructor called." << std::endl;
}
// Copy Assignment Operator
Dog& Dog::operator=(const Dog& other) {
	if (this == &other) return *this;
	_type = other._type;
	std::cout << "Dog: Copy assignment operator called." << std::endl;
	return *this;
}
// Getters
// Setters
// Other
	void Animal::makeSound(void) { std::cout << "Appropriate sound for an undefined dog" << std::endl; }