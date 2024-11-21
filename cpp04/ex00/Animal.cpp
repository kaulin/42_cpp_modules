#include "Animal.hpp"

// Default Constructor
Animal::Animal () : _type("Undefined animal") {
	std::cout << "Animal: Default constructor called." << std::endl;
}
// Destructor
Animal::~Animal() {
	std::cout << "Animal: Destructor called." << std::endl;
}
// Getters
	const std::string& Animal::getType() const { return _type; }
// Setters
// Other
	void Animal::makeSound() const { std::cout << "Appropriate sound for an undefined animal" << std::endl; }