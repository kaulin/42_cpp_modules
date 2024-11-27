#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::_implementEnactment() const {}

// Default Constructor
AForm::AForm() : _name("NAME"), _gradeToSign(150), _gradeToExec(150) {
	std::cout << "AForm: Default constructor called.\n";;
}
// Parameterized Constructor
AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExec) : 
	_name(name), 
	_signedStatus(false), 
	_gradeToSign(gradeToSign), 
	_gradeToExec(gradeToExec) {
	std::cout << "AForm: Parameterized constructor called.\n";;
	if (name.length() == 0) throw std::invalid_argument("empty string");
	if (gradeToSign < 1 || gradeToExec < 1) throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150) throw AForm::GradeTooLowException();
}
// Copy Constructor
AForm::AForm(const AForm& other) : 
	_name(other._name), 
	_signedStatus(false), 
	_gradeToSign(other._gradeToSign), 
	_gradeToExec(other._gradeToExec) {
	std::cout << "AForm: Copy constructor called.\n";;
}
// Destructor
AForm::~AForm() {
	std::cout << "AForm: Destructor called.\n";;
}
// Copy Assignment Operators
AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm: Copy assignment operator called.\n";;
	if (this == &other) return *this;
	return *this;
}
// Getters
const std::string& AForm::getName() const { return _name; }
bool AForm::getSignedStatus() const { return _signedStatus; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExec() const { return _gradeToExec; }
// Setters
// Other
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_signedStatus) throw std::runtime_error("form already signed");
	if (bureaucrat.getGrade() > _gradeToSign) throw AForm::GradeTooLowException();
	_signedStatus = true;\
}
void AForm::execute(Bureaucrat const & executor) const {
	if (!_signedStatus) throw std::runtime_error("form not signed");
	if (executor.getGrade() > _gradeToExec) throw AForm::GradeTooLowException();
	_implementEnactment();
}

// Exceptions
const char* AForm::GradeTooLowException::what() const throw () { return "grade too low"; }
const char* AForm::GradeTooHighException::what() const throw () { return "grade too high"; }

// Insertion Operator
std::ostream& operator<<(std::ostream& os, const AForm& aform) {
	os << aform.getName() << ":\n Grade to sign = " << aform.getGradeToSign() << "\n Grade to execute = " << aform.getGradeToExec() << "\n Status: " << ((aform.getSignedStatus()) ? "signed" : "not signed");
	return os;
}