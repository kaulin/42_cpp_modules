#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
public:
	// Default Constructor
	Dog();
	// Copy Constructor
	Dog(const Dog& other);
	// Destructor
	~Dog();
	// Copy Assignment Operator
	Dog& operator=(const Dog& other);

	// Getters
	// Setters
	// Other
	void makeSound() const;
};

#endif
