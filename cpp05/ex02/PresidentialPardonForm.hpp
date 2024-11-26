#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	const std::string	_target;
	// Default Constructor
	PresidentialPardonForm();
	// Copy Constructor
	PresidentialPardonForm(const PresidentialPardonForm& other);
	// Copy Assignment Operator
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	void _implementEnactment() const override;
public:
	// Parameterized Constructor
	PresidentialPardonForm(const std::string& target);
	// Destructor
	~PresidentialPardonForm();

	// Getters
	// Setters
	// Other
};