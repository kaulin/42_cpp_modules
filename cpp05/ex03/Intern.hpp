#pragma once

#include <iostream>

class MyClass {
private:
	std::string	_name;
public:
	// Default Constructor
	MyClass();
	// Parameterized Constructor
	MyClass(const std::string& name);
	// Copy Constructor
	MyClass(const MyClass& other);
	// Destructor
	~MyClass();
	// Copy Assignment Operator
	MyClass& operator=(const MyClass& other);

	// Getters
	const std::string&	getName() const;
	// Setters
	void		setName(std::string _name);
	// Other
};