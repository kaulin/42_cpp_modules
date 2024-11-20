#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
private:
	std::string	_type;
public:
	// Default Constructor
	Cat();
	// Parameterized Constructor
	Cat(const std::string& name);
	// Destructor
	~Cat();
	// Copy Constructor
	Cat(const Cat& other);
	// Copy Assignment Operator
	Cat& operator=(const Cat& other);

	// Getters
	// Setters
	// Other
};

#endif
