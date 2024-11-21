#include "Dog.hpp"

// Default Constructor
Dog::Dog () {
	std::cout << "Dog: Default constructor called." << std::endl;
	_type = "Dog";
}
// Destructor
Dog::~Dog() {
	std::cout << "Dog: Destructor called." << std::endl;
}
// Getters
// Setters
// Other
	void Dog::makeSound(void) const { std::cout << "BORK BORK" << std::endl; }