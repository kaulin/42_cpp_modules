#include "Cat.hpp"

// Default Constructor
Cat::Cat () : _brain(new Brain()) {
	std::cout << "Cat: Default constructor called." << std::endl;
	_type = "Cat";
}
// Copy Constructor
Cat::Cat(const Cat& other) : _brain(new Brain()) {
	std::cout << "Cat: Copy constructor called." << std::endl;
	_type = other._type;
}
// Destructor
Cat::~Cat() {
	std::cout << "Cat: Destructor called." << std::endl;
	delete _brain;
}
// Copy Assignment Operator
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	_type = other._type;
	*_brain = *other._brain;
	return *this;
}
// Getters
	const std::string Cat::getIdea(const int n) const { return _brain->getIdea(n); }
// Setters
// Other
	void Cat::makeSound() const { std::cout << "MEOW MEOW!!!" << std::endl; }