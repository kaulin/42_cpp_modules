#include "Dog.hpp"

// Default Constructor
Dog::Dog () {
	std::cout << "Dog: Default constructor called." << std::endl;
	_type = "Dog";
}
// Copy Constructor
Dog::Dog(const Dog& other) {
	std::cout << "Dog: Copy constructor called." << std::endl;
	_type = other._type;
}
// Destructor
Dog::~Dog() {
	std::cout << "Dog: Destructor called." << std::endl;
}
// Copy Assignment Operator
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	_type = other._type;
	return *this;
}
// Getters
// Setters
// Other
	void Dog::makeSound() const { std::cout << "BORK BORK!!!" << std::endl; }