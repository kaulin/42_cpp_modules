#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* _brain;
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
	const std::string getIdea(const int n) const;
	// Setters
	// Other
	void makeSound() const;
	void brainwash();
};

#endif
