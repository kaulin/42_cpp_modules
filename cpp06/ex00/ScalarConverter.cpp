#include "ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <cctype>

bool isChar(const std::string& literal) {
	return literal.length() == 1 && std::isprint(literal[0]);
}

bool isInt(const std::string& literal) {
	if (literal.find(".") != std::string::npos)
		return false;
	try {
		std::stoi(literal);
		return true;
	} catch (std::invalid_argument& e) {
		return false;
	} catch (std::out_of_range& e) {
		return false;
	}
}

bool isFloat(const std::string& literal) {
	if (literal.back() != 'f' && literal.back() != 'F')
		return false;
	std::istringstream inputstream(literal.substr(0, literal.size() -1));
	float f;
	inputstream >> f;
	return inputstream.eof() && !inputstream.fail();
}

bool isDouble(const std::string& literal) {
	std::istringstream inputstream(literal);
	double d;
	inputstream >> d;
	return inputstream.eof() && !inputstream.fail();
}

// void convertChar() {

// }

// void convertInt() {

// }

// void convertFloat() {

// }

// void convertDouble() {

// }

// Default Constructora
ScalarConverter::ScalarConverter () {}
// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
// Destructor
ScalarConverter::~ScalarConverter() {}
// Copy Assignment Operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { 
	(void)other;
	return *this;
}

/*
	Convert
*/
void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty())
		std::cout << "Error: empty literal\n";
	else if (isChar(literal))
		std::cout << literal << " is a char\n";
	else if (isInt(literal))
		std::cout << literal << " is an int\n";
	else if (isFloat(literal))
		std::cout << literal << " is a float\n";
	else if (isDouble(literal))
		std::cout << literal << " is a double\n";
	else
		std::cout << "I dont know what you're talking about...\n";
}