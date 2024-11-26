#include "PresidentialPardonForm.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm() : 
	AForm("PresidentialPardonForm", 25, 5), 
	_target("TARGET") {
	std::cout << "PresidentialPardonForm: Default constructor called." << std::endl;
}
// Parameterized Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :  
	AForm("PresidentialPardonForm", 25, 5), 
	_target(target) {
	std::cout << "PresidentialPardonForm: Parameterized constructor called." << std::endl;
	if (target.length() == 0) throw std::invalid_argument("empty name");
}
// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :  
	AForm("PresidentialPardonForm", 25, 5), 
	_target(other._target) {
	std::cout << "PresidentialPardonForm: Copy constructor called." << std::endl;
}
// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: Destructor called." << std::endl;
}
// Copy Assignment Operators
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "PresidentialPardonForm: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	return *this;
}
// Getters
// Setters
// Other
void PresidentialPardonForm::_implementEnactment() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!\n";
}