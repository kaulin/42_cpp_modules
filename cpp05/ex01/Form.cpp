#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
Form::Form() : _name("NAME"), _gradeToSign(150), _gradeToExec(150) {
	std::cout << "Form: Default constructor called." << std::endl;
}
// Parameterized Constructor
Form::Form(const std::string& name, const int gradeToSign, const int gradeToExec) : 
	_name(name), 
	_signedStatus(false), 
	_gradeToSign(gradeToSign), 
	_gradeToExec(gradeToExec) {
	std::cout << "Form: Parameterized constructor called." << std::endl;
	if (name.length() == 0) throw std::invalid_argument("empty name");
	if (gradeToSign < 1 || gradeToExec < 1) throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150) throw Form::GradeTooLowException();
}
// Copy Constructor
Form::Form(const Form& other) : 
	_name(other._name), 
	_signedStatus(false), 
	_gradeToSign(other._gradeToSign), 
	_gradeToExec(other._gradeToExec) {
	std::cout << "Form: Copy constructor called." << std::endl;
}
// Destructor
Form::~Form() {
	std::cout << "Form: Destructor called." << std::endl;
}
// Copy Assignment Operators
Form& Form::operator=(const Form& other) {
	std::cout << "Form: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	return *this;
}
// Getters
const std::string& Form::getName() const { return _name; }
bool Form::getSignedStatus() const { return _signedStatus; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExec() const { return _gradeToExec; }
// Setters
// Other
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (_signedStatus) throw std::runtime_error("form already signed");
	if (bureaucrat.getGrade() > _gradeToSign) throw Form::GradeTooLowException();
	_signedStatus = true;
}

// Exceptions
const char* Form::GradeTooLowException::what() const throw () { return "grade too low"; }
const char* Form::GradeTooHighException::what() const throw () { return "grade too high"; }

// Insertion Operator
std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << form.getName() << ":\n Grade to sign = " << form.getGradeToSign() << "\n Grade to execute = " << form.getGradeToExec() << "\n Status: " << ((form.getSignedStatus()) ? "signed" : "not signed");
	return os;
}