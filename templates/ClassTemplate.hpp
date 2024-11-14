#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>

class MyClass {
private:
	std::string	_name;
public:
	// Default Constructor
	MyClass();
	// Parameterized Constructor
	MyClass(std::string name);
	// Destructor
	~MyClass();
	// Copy Constructor
	MyClass(const MyClass& other);
	// Copy Assignment Operator
	MyClass& operator=(const MyClass& other);

	// Getters
	std::string	getName(void);
	// Setters
	void		setName(std::string _name);
	// Other
};

#endif
