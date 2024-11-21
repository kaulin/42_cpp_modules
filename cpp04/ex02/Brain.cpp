#include <string>
#include "Brain.hpp"

// Default Constructor
Brain::Brain () {
	std::cout << "Brain: Default constructor called." << std::endl;
	for (int i = 0; i < 100; i++) _ideas[i] = "Idea number " + std::to_string(i);
}
// Copy Constructor
Brain::Brain(const Brain& other) {
	std::cout << "Brain: Copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++) _ideas[i] = other._ideas[i];
}
// Destructor
Brain::~Brain() {
	std::cout << "Brain: Destructor called." << std::endl;
}
// Copy Assignment Operator
Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	for (int i = 0; i < 100; i++) _ideas[i] = other._ideas[i];
	return *this;
}
// Getters
	const std::string Brain::getIdea(const int n) const { 
		if (n < 0 || n >= 100) return "";
		return _ideas[n];
	}
// Setters
// Other
	void Brain::brainwash() {
		std::cout << "Brain being washed!" << std::endl;
		for (int i = 0; i < 100; i++) _ideas[i] = "Clean idea number " + std::to_string(i);
	}