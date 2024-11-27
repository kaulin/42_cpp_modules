#pragma once

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
	// Copy Constructor
	Intern(const Intern& other);
	// Copy Assignment Operator
	Intern& operator=(const Intern& other);
	AForm* makeShrubberyCreationForm(const std::string& target) const;
	AForm* makeRobotomyRequestForm(const std::string& target) const;
	AForm* makePresidentialPardonForm(const std::string& target) const;
public:
	// Default Constructor
	Intern();
	// Destructor
	~Intern();
	// Getters
	// Setters
	// Other
	AForm* makeForm(const std::string& formName, const std::string& formTarget) const;
};