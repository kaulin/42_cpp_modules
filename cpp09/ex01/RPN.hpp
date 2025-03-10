#pragma once

#include <iostream>

class RPN {
private:
	std::string	_name;
public:
	// Default Constructor
	RPN();
	// Parameterized Constructor
	RPN(const std::string& name);
	// Copy Constructor
	RPN(const RPN& other);
	// Destructor
	~RPN();
	// Copy Assignment Operator
	RPN& operator=(const RPN& other);

	// Getters
	const std::string&	getName() const;
	// Setters
	void		setName(std::string _name);
	// Other
};