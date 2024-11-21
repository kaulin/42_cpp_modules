#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat () {
	std::cout << "Default constructor called." << std::endl;
}
// Parameterized Constructor
Bureaucrat::Bureaucrat (const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade)
	std::cout << "Parameterized constructor called." << std::endl;
}
// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
	std::cout << "Copy constructor called." << std::endl;
}
// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called." << std::endl;
}
// Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other) return *this;
	_name = other._name;
	std::cout << "Copy assignment operator called." << std::endl;
	return *this;
}
// Getters
const std::string&	Bureaucrat::getName() const { return _name;}
// Setters
// Other
void Bureaucrat::promote() {

}
void Bureaucrat::demote() {

}