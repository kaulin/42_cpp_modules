#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	std::cout << "Creating a bureaucracy!\n";
	
	std::cout << "\nTrying to init Presidential Pardon Form with empty target\n";
	try { 
		PresidentialPardonForm form("");
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nInit Presidential Pardon Form and Borgov the Bureaucrat with sufficient grade to sign and execute it\n";
	try { 
		PresidentialPardonForm form("Kitty");
		Bureaucrat borgov("Borgov", 1);
		borgov.executeForm(form);
		borgov.signForm(form);
		borgov.signForm(form);
		borgov.executeForm(form);
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	return 0;
} 