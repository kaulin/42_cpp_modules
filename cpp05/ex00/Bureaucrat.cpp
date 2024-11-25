#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat() : _name("NAME"), _grade(150) {
	std::cout << "Bureaucrat: Default constructor called." << std::endl;
}
// Parameterized Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	std::cout << "Bureaucrat: Parameterized constructor called." << std::endl;
	if (grade < 1) throw Bureaucrat::GradeTooLowException();
	if (grade > 150) throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}
// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat: Copy constructor called." << std::endl;
}
// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: Destructor called." << std::endl;
}
// Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	_grade = other._grade;
	return *this;
}
// Getters
const std::string&	Bureaucrat::getName() const { return _name; }
int					Bureaucrat::getGrade() const { return _grade; }
// Setters
// Other
void Bureaucrat::promote() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}
void Bureaucrat::demote() {
	if (_grade + 1 > 150) throw Bureaucrat::GradeTooLowException();
	_grade++;
}

// Exceptions
const char* Bureaucrat::GradeTooLowException::what() const throw () { return "grade too low"; }
const char* Bureaucrat::GradeTooHighException::what() const throw () { return "grade too high"; }

// Insertion Operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}