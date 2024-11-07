#ifndef Class_HPP
# define Class_HPP

#include <iostream>

class Class
{
private:
	std::string	_name;
public:
	// Construct
	Class();
	Class(std::string name);
	// Destroy
	~Class();
	// Get
	std::string	getName(void);
	// Set
	void	setName(std::string _name);
	// Other
};

#endif