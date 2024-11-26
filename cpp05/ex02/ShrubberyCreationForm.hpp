#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	const std::string	_target;
	// Default Constructor
	ShrubberyCreationForm();
	// Copy Constructor
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	// Copy Assignment Operator
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	void _implementEnactment() const override;
public:
	// Parameterized Constructor
	ShrubberyCreationForm(const std::string& target);
	// Destructor
	~ShrubberyCreationForm();

	// Getters
	// Setters
	// Other
};