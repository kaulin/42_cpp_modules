#include "Dog.hpp"

// Default Constructor
Dog::Dog () : _brain(new Brain()) {
	std::cout << "Dog: Default constructor called." << std::endl;
	_type = "Dog";
}
// Copy Constructor
Dog::Dog(const Dog& other) : _brain(new Brain()) {
	std::cout << "Dog: Copy constructor called." << std::endl;
	_type = other._type;
}
// Destructor
Dog::~Dog() {
	std::cout << "Dog: Destructor called." << std::endl;
	delete _brain;
}
// Copy Assignment Operator
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	_type = other._type;
	*_brain = *other._brain;
	return *this;
}
// Getters
	const std::string Dog::getIdea(const int n) const { return _brain->getIdea(n); }
// Setters
// Other
	void Dog::makeSound() const { std::cout << "BORK BORK!!!" << std::endl; }
	void Dog::brainwash() { _brain->brainwash(); }