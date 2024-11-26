#pragma once

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_signedStatus;
	const int			_gradeToSign;
	const int			_gradeToExec;
protected:
	// Default Constructor
	AForm();
	// Copy Constructor
	AForm(const AForm& other);
	// Copy Assignment Operator
	AForm& operator=(const AForm& other);
	virtual void _implementEnactment() const = 0;
public:
	// Parameterized Constructor
	AForm(const std::string& name, const int gradeToSign, const int gradeToExec);
	// Destructor
	virtual ~AForm();

	// Getters
	const std::string& getName() const;
	bool getSignedStatus() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	// Setters
	// Other
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(Bureaucrat const & executor) const;

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
std::ostream& operator<< (std::ostream& os, const AForm& aform);