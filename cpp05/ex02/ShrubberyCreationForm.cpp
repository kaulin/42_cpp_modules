#include "ShrubberyCreationForm.hpp"

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("ShrubberyCreationForm", 145, 137), 
	_target("TARGET") {
	std::cout << "ShrubberyCreationForm: Default constructor called." << std::endl;
}
// Parameterized Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :  
	AForm("ShrubberyCreationForm", 145, 137), 
	_target(target) {
	std::cout << "ShrubberyCreationForm: Parameterized constructor called." << std::endl;
	if (target.length() == 0) throw std::invalid_argument("empty name");
}
// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :  
	AForm("ShrubberyCreationForm", 145, 137), 
	_target(other._target) {
	std::cout << "ShrubberyCreationForm: Copy constructor called." << std::endl;
}
// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: Destructor called." << std::endl;
}
// Copy Assignment Operators
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	return *this;
}
// Getters
// Setters
// Other
void ShrubberyCreationForm::_implementEnactment() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!\n";
}