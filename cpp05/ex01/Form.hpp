#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>
class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_signedStatus;
	const int			_gradeToSign;
	const int			_gradeToExec;
	// Default Constructor
	Form();
	// Copy Constructor
	Form(const Form& other);
	// Copy Assignment Operator
	Form& operator=(const Form& other);
public:
	// Parameterized Constructor
	Form(const std::string& name, const int gradeToSign, const int gradeToExec);
	// Destructor
	~Form();

	// Getters
	const std::string& getName() const;
	bool getSignedStatus() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	// Setters
	// Other
	void beSigned(const Bureaucrat& bureaucrat);

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
std::ostream& operator<< (std::ostream& os, const Form& form);

#endif
