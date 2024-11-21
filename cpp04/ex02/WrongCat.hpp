#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	// Default Constructor
	WrongCat();
	// Copy Constructor
	WrongCat(const WrongCat& other);
	// Destructor
	~WrongCat();
	// Copy Assignment Operator
	WrongCat& operator=(const WrongCat& other);

	// Getters
	// Setters
	// Other
	void makeSound(void) const;
};

#endif
