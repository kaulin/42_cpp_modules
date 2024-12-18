#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {
	std::cout << "Creating a bureaucracy!\n";


	std::cout << "\nTrying to init b with empty name\n";
	try { 
		Bureaucrat b("", 1);
		std::cout << b << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	std::cout << "\nTrying to init b with grade 0\n";
	try { 
		Bureaucrat b("b", 0);
		std::cout << b << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }
	
	std::cout << "\nTrying to init b with grade 151\n";
	try { 
		Bureaucrat b("b", 151);
		std::cout << b << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }
		
	std::cout << "\nTrying to init b with grade 1\n";
	try { 
		Bureaucrat b("b", 1);
		std::cout << b << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }
	
	std::cout << "\nTrying to init b with grade 150\n";
	try { 
		Bureaucrat b("b", 150);
		std::cout << b << " created successfully!\n";
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }
	
	std::cout << "\nFollowing the career of Bubbles the Bureaucrat:\n";
	Bureaucrat bubbles("Bubbles", 150);
	
	std::cout << "Trying to demote " << bubbles << "\n";
	try { 
		bubbles.demote();
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }
	
	for (int i = 0; i < 150; i++) {
		std::cout << "Trying to promote " << bubbles << "\n";
		try { 
			bubbles.promote();
		}
		catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }
	}
	
	std::cout << "Trying to demote " << bubbles << "\n";
	try { 
		bubbles.demote();
	}
	catch (std::exception & e) { std::cout << "Caught exception: " << e.what() << "\n"; }

	return 0;
}