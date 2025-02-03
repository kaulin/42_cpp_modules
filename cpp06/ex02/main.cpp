#include <iostream>
#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0,2);
	int outcome = distribution(generator);
	switch(outcome) {
		case 0:
			std::cout << "Created class A!\n";
			return new A();
		case 1:
			std::cout << "Created class B!\n";
			return new B();
		case 2:
			std::cout << "Created class C!\n";
			return new C();
	}
	std::cout << "Error creating child class object!\n";
	return nullptr;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Base pointer identified as class A!\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Base pointer identified as class B!\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Base pointer identified as class C!\n";
	else
		std::cout << "Base pointer could not be identified!\n";
}

void identify(Base& p) {
	try {
		A& tempA = dynamic_cast<A&>(p);
		
		std::cout << "Base reference identified as class A!\n";
		(void)tempA;
		return;
	} catch (std::exception &exception) {}
	try {
		B& tempB = dynamic_cast<B&>(p);
		
		std::cout << "Base reference identified as class B!\n";
		(void)tempB;
		return;
	} catch (std::exception &exception) {}
	try {
		C& tempC = dynamic_cast<C&>(p);
		
		std::cout << "Base reference identified as class C!\n";
		(void)tempC;
		return;
	} catch (std::exception &exception) {}
	std::cout << "Base reference could not be identified!\n";
}


int main (int argc, char** argv) {
	if (argc != 1) {
		std::cerr << "Usage: " << argv[0] << "\n";
		return 1;
	}
	std::cout << "TESTING CLASS IDENTIFICATION\n";
	Base* pointer = generate();
	if (!pointer)
		return (1);
	identify(pointer);
	identify(*pointer);
	delete pointer;
	return 0;
}