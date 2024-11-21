#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
public:
	// Default Constructor
	Cat();
	// Parameterized Constructor
	Cat(const std::string& name) = delete;
	// Destructor
	~Cat();
	// Copy Constructor
	Cat(const Cat& other) = delete;
	// Copy Assignment Operator
	Cat& operator=(const Cat& other) = delete;

	// Getters
	// Setters
	// Other
	void makeSound(void) const;
};

#endif
