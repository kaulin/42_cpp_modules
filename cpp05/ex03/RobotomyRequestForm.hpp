#pragma once

#include <iostream>
#include <exception>
#include <random>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	const std::string	_target;
	// Default Constructor
	RobotomyRequestForm();
	// Copy Constructor
	RobotomyRequestForm(const RobotomyRequestForm& other);
	// Copy Assignment Operator
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	void _implementEnactment() const override;
public:
	// Parameterized Constructor
	RobotomyRequestForm(const std::string& target);
	// Destructor
	~RobotomyRequestForm();

	// Getters
	// Setters
	// Other
};