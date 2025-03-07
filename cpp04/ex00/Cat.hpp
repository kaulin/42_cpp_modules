#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
public:
	// Default Constructor
	Cat();
	// Copy Constructor
	Cat(const Cat& other);
	// Destructor
	~Cat();
	// Copy Assignment Operator
	Cat& operator=(const Cat& other);

	// Getters
	// Setters
	// Other
	void makeSound() const;
};

#endif
