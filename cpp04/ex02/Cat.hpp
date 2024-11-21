#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain* _brain;
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
	const std::string getIdea(const int n) const;
	// Setters
	// Other
	void makeSound() const;
};

#endif
