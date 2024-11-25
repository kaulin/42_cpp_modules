#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;
	// Default Constructor
	Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& other);
	Bureaucrat(const Bureaucrat& other);
public:
	// Parameterized Constructor
	Bureaucrat(const std::string& name, int grade);
	// Copy Constructor
	// Destructor
	~Bureaucrat();
	// Copy Assignment Operator

	// Getters
	const std::string&	getName() const;
	int					getGrade() const;
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

#endif
