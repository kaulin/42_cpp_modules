#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	std::cout << "Creating a bureaucracy!\n";
	
	std::cout << "\nTrying to init Presidential Pardon Form with empty target\n";
	try { 
		PresidentialPardonForm form("");
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nTest Presidential Pardon Form with Borgov and Bubbles\n";
	try { 
		PresidentialPardonForm form("Kitty");
		std::cout << "Created " << form << "\n";
		Bureaucrat borgov("Borgov", 1);
		Bureaucrat bubbles("Bubbles", 26);
		std::cout << "Created " << borgov << ", and " << bubbles << "\n";
		borgov.executeForm(form);
		bubbles.signForm(form);
		bubbles.promote();
		bubbles.signForm(form);
		bubbles.executeForm(form);
		borgov.signForm(form);
		borgov.executeForm(form);
		std::cout << form << "\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nTrying to init Robotomy Request Form with empty target\n";
	try { 
		RobotomyRequestForm form("");
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nTest Robotomy Request Form with Borgov and Bubbles\n";
	try { 
		RobotomyRequestForm form("Marvin");
		std::cout << "Created " << form << "\n";
		Bureaucrat borgov("Borgov", 1);
		Bureaucrat bubbles("Bubbles", 73);
		std::cout << "Created " << borgov << ", and " << bubbles << "\n";
		borgov.executeForm(form);
		bubbles.signForm(form);
		bubbles.promote();
		bubbles.signForm(form);
		bubbles.executeForm(form);
		borgov.signForm(form);
		borgov.executeForm(form);
		borgov.executeForm(form);
		borgov.executeForm(form);
		borgov.executeForm(form);
		borgov.executeForm(form);
		borgov.executeForm(form);
		borgov.executeForm(form);
		borgov.executeForm(form);
		borgov.executeForm(form);
		borgov.executeForm(form);
		std::cout << form << "\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

std::cout << "\nTrying to init Shrubbery Creation Form with empty target\n";
	try { 
		ShrubberyCreationForm form("");
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

		std::cout << "\nTest Shrubbery Creation Form with Borgov and Bubbles\n";
	try { 
		ShrubberyCreationForm form("ResidentialDistrict42");
		std::cout << "Created " << form << "\n";
		Bureaucrat borgov("Borgov", 1);
		Bureaucrat bubbles("Bubbles", 146);
		std::cout << "Created " << borgov << ", and " << bubbles << "\n";
		borgov.executeForm(form);
		bubbles.signForm(form);
		bubbles.promote();
		bubbles.signForm(form);
		bubbles.executeForm(form);
		borgov.signForm(form);
		borgov.executeForm(form);
		std::cout << form << "\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	return 0;
} 