#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
	std::cout << "Creating a bureaucracy!\n";

	Bureaucrat borgov("Borgov", 1);
	std::cout << "Created " << borgov << "\n";
	Bureaucrat bubbles("Bubbles", 25);
	std::cout << "Created " << bubbles << "\n";
	Intern inka;
	AForm* form = nullptr;

	std::cout << "\nPardon: From init to execute\n";
	try { 
		form = inka.makeForm("presidential pardon", "Vilja");
		if (!form) throw std::invalid_argument ("form creation failed");
		std::cout << *form << "\n";
		bubbles.signForm(*form);
		borgov.executeForm(*form);
		std::cout << *form << "\n";
		delete form;
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nRobotomy: From init to execute\n";
	try { 
		form = inka.makeForm("robotomy request", "Marvin");
		if (!form) throw std::invalid_argument ("form creation failed");
		std::cout << *form << "\n";
		bubbles.signForm(*form);
		borgov.executeForm(*form);
		std::cout << *form << "\n";
		delete form;
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nShrubbery: From init to execute\n";
	try { 
		form = inka.makeForm("shrubbery creation", "ResidentialDistrict42");
		if (!form) throw std::invalid_argument ("form creation failed");
		std::cout << *form << "\n";
		bubbles.signForm(*form);
		borgov.executeForm(*form);
		std::cout << *form << "\n";
		delete form;
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nFailed form init, empty target\n";
	try { 
		form = inka.makeForm("shrubbery creation", "");
		if (!form) throw std::invalid_argument ("form creation failed");
		std::cout << *form << "\n";
		bubbles.signForm(*form);
		borgov.executeForm(*form);
		std::cout << *form << "\n";
		delete form;
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nFailed form init, empty form name\n";
	try { 
		form = inka.makeForm("", "ResidentialDistrict42");
		if (!form) throw std::invalid_argument ("form creation failed");
		std::cout << *form << "\n";
		bubbles.signForm(*form);
		borgov.executeForm(*form);
		std::cout << *form << "\n";
		delete form;
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nFailed form init, unknown form type\n";
	try { 
		form = inka.makeForm("overthrow government", "asap");
		if (!form) throw std::invalid_argument ("form creation failed");
		std::cout << *form << "\n";
		bubbles.signForm(*form);
		borgov.executeForm(*form);
		std::cout << *form << "\n";
		delete form;
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	return 0;
} 