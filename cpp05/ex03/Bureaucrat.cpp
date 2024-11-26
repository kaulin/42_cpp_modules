#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat() : _name("NAME"), _grade(150) {
	std::cout << "Bureaucrat: Default constructor called.\n";;
}
// Parameterized Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	std::cout << "Bureaucrat: Parameterized constructor called.\n";;
	if (name.length() == 0) throw std::invalid_argument("empty name");
	if (grade < 1) throw Bureaucrat::GradeTooLowException();
	if (grade > 150) throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}
// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat: Copy constructor called.\n";;
}
// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: Destructor called.\n";;
}
// Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat: Copy assignment operator called.\n";;
	if (this == &other) return *this;
	_grade = other._grade;
	return *this;
}
// Getters
const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }
// Setters
// Other
void Bureaucrat::promote() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << _name << " the Bureaucrat promoted to grade " << _grade << "\n";
}
void Bureaucrat::demote() {
	if (_grade + 1 > 150) throw Bureaucrat::GradeTooLowException();
	_grade++;
		std::cout << _name << " the Bureaucrat demoted to grade " << _grade << "\n";
}
void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "\n";
	}
	catch (std::exception & e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
	}
}
void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "\n";
	}
	catch (std::exception & e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << "\n";
	}
}

// Exceptions
const char* Bureaucrat::GradeTooLowException::what() const throw () { return "grade too low"; }
const char* Bureaucrat::GradeTooHighException::what() const throw () { return "grade too high"; }

// Insertion Operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}