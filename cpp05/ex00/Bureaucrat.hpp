#pragma once

#include <iostream>
#include <exception>

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;
	// Default Constructor
	Bureaucrat();
	// Copy Constructor
	Bureaucrat(const Bureaucrat& other);
	// Copy Assignment Operator
	Bureaucrat& operator=(const Bureaucrat& other);
public:
	// Parameterized Constructor
	Bureaucrat(const std::string& name, int grade);
	// Destructor
	~Bureaucrat();

	// Getters
	const std::string& getName() const;
	int getGrade() const;
	// Setters
	// Other
	void promote();
	void demote();

	// Exceptions
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw () override;
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw () override;
	};
};

// Insertion Operator
std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat);
