#include "Intern.hpp"

// Default Constructor
Intern::Intern () {
	std::cout << "Intern: Default constructor called.\n";;
}
// Copy Constructor
Intern::Intern(const Intern& other) {
	std::cout << "Intern: Copy constructor called.\n";;
	(void)other;
}
// Destructor
Intern::~Intern() {
	std::cout << "Intern: Destructor called.\n";;
}
// Copy Assignment Operator
Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern: Copy assignment operator called.\n";;
	if (this == &other) return *this;
	return *this;
}
// Getters
// Setters
// Other
AForm* Intern::makeShrubberyCreationForm(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}
AForm* Intern::makeRobotomyRequestForm(const std::string& target) const {
	return new RobotomyRequestForm(target);
}
AForm* Intern::makePresidentialPardonForm(const std::string& target) const {
	return new PresidentialPardonForm(target);
}
AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) const {
	std::string formNames[3] = {
		"shrubbery creation", 
		"robotomy request", 
		"presidential pardon"};
	AForm* (Intern::*functions[3])(const std::string& target) const = { 
		&Intern::makeShrubberyCreationForm, 
		&Intern::makeRobotomyRequestForm, 
		&Intern::makePresidentialPardonForm };
	AForm* form = nullptr;
	int index = 2;
	while (index >= 0 && formName != formNames[index]) {
		index--;
	}
	switch (index)
	{
		case -1:
			std::cout << "The intern must have mixed up the form names again...\n";
			break;
		default:
			try {
				form = (this->*functions[index])(formTarget);
				std::cout << "Intern creates " << form->getName() << "\n";
			}
			catch (std::exception& e) { std::cout << "Intern failed to create form because " << e.what() << "\n"; }
	}
	return form;
}