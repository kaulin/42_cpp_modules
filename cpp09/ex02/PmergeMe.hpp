#pragma once

#include <iostream>

class PmergeMe {
private:
	std::string	_name;
public:
	// Default Constructor
	PmergeMe();
	// Parameterized Constructor
	PmergeMe(const std::string& name);
	// Copy Constructor
	PmergeMe(const PmergeMe& other);
	// Destructor
	~PmergeMe();
	// Copy Assignment Operator
	PmergeMe& operator=(const PmergeMe& other);

	// Getters
	const std::string&	getName() const;
	// Setters
	void		setName(std::string _name);
	// Other
};