#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
public:
	// Default Constructor
	Dog();
	// Parameterized Constructor
	Dog(const std::string& name) = delete;
	// Destructor
	~Dog();
	// Copy Constructor
	Dog(const Dog& other) = delete;
	// Copy Assignment Operator
	Dog& operator=(const Dog& other) = delete;

	// Getters
	// Setters
	// Other
	void makeSound(void) const;
};

#endif
