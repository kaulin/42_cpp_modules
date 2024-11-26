#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	std::cout << "Creating a bureaucracy!\n";
	
	std::cout << "\nTrying to init F with empty name\n";
	try { 
		Form f("", 150, 150);
		std::cout << f << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nTrying to init F with gradeToSign 151\n";
	try { 
		Form f("F", 151, 150);
		std::cout << f << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }
	
	std::cout << "\nTrying to init F with gradeToExec 151\n";
	try { 
		Form f("F", 150, 151);
		std::cout << f << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nTrying to init F with gradeToSign 0\n";
	try { 
		Form f("F", 151, 0);
		std::cout << f << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }
	
	std::cout << "\nTrying to init F with gradeToExec 0\n";
	try { 
		Form f("F", 150, 0);
		std::cout << f << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nTrying to init F with gradeToSign && gradeToExec 151\n";
	try { 
		Form f("F", 151, 151);
		std::cout << f << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }
	
	std::cout << "\nTrying to init F with gradeToSign && gradeToExec 0\n";
	try { 
		Form f("F", 0, 0);
		std::cout << f << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nInit Bubbles the Bureaucrat and forms F1, F75 and F150\n";

	Bureaucrat bubbles("Bubbles", 150);
	Form f1("F1", 1, 50);
	Form f75("F75", 75, 100);
	Form f150("F150", 150, 150);

	std::cout << "\nNew employee: " << bubbles << "\n";
	std::cout << "\nTODO:\n";
	std::cout << f1 << "\n";
	std::cout << f75 << "\n";
	std::cout << f150 << "\n";

	bubbles.signForm(f1);
	bubbles.signForm(f75);
	bubbles.signForm(f150);
	while (!(f1.getSignedStatus() && f75.getSignedStatus() && f150.getSignedStatus())) {
		if (!(f1.getSignedStatus())) bubbles.signForm(f1);
		if (!(f75.getSignedStatus())) bubbles.signForm(f75);
		if (!(f150.getSignedStatus())) bubbles.signForm(f150);
		try
		{
			bubbles.promote();
		}
		catch(const std::exception& e) { std::cout << bubbles << ", could not be promoted because " << e.what() << '\n'; }
	}
	
	std::cout << "\nEmployee of the month: " << bubbles << "\n";
	std::cout << "\nDONE:\n";
	std::cout << f1 << "\n";
	std::cout << f75 << "\n";
	std::cout << f150 << "\n";

	return 0;
}