#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
private:
	std::string	_type;
public:
	// Default Constructor
	Dog();
	// Parameterized Constructor
	Dog(const std::string& name);
	// Destructor
	~Dog();
	// Copy Constructor
	Dog(const Dog& other);
	// Copy Assignment Operator
	Dog& operator=(const Dog& other);

	// Getters
	// Setters
	// Other
};

#endif
