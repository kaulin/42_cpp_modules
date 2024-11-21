#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;
public:
	// Default Constructor
	Bureaucrat();
	// Parameterized Constructor
	Bureaucrat(const std::string& name, int grade);
	// Copy Constructor
	Bureaucrat(const Bureaucrat& other);
	// Destructor
	~Bureaucrat();
	// Copy Assignment Operator
	Bureaucrat& operator=(const Bureaucrat& other);

	// Getters
	const std::string&	getName() const;
	const int			getGrade() const;
	// Setters
	// Other
	void promote();
	void demote();
};

#endif
