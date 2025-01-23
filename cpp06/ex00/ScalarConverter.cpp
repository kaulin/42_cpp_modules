#include "ScalarConverter.hpp"

bool isChar(const std::string& literal) {
	return literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]);
}

bool isInt(const std::string& literal) {
std::istringstream inputstream(literal);
	int i;
	inputstream >> i;
	return inputstream.eof() && !inputstream.fail();
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

// Default Constructor
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
	char cVal;
	int iVal;
	float fVal;
	double dVal;
	std::ostringstream cStream;
	std::ostringstream iStream;
	std::ostringstream fStream;
	std::ostringstream dStream;
	fStream << std::fixed << std::setprecision(1);
	dStream << std::fixed << std::setprecision(1);
	if (literal.empty())
		std::cout << "Error: empty literal\n";
	else if (isChar(literal)) {
		cVal = literal[0];
		cStream << cVal;
		iStream << static_cast<int>(cVal);
		fStream << static_cast<float>(cVal);
		dStream << static_cast<double>(cVal);
	}
	else if (isInt(literal)) {
		iVal = std::stoi(literal);
		iStream << iVal;
		if (iVal < 0 || iVal > 127) cStream << "impossible";
		else if (!std::isprint(iVal)) cStream << "Not displayable";
		else cStream << static_cast<char>(iVal);
		cStream << static_cast<char>(iVal);
		fStream << static_cast<float>(iVal);
		dStream << static_cast<double>(iVal);
	}
	else if (isFloat(literal)) {
		fVal = std::stof(literal);
		fStream << fVal;
		cStream << static_cast<char>(fVal);
		iStream << static_cast<int>(fVal);
		dStream << static_cast<double>(fVal);
	}
	else if (isDouble(literal)) {
		dVal = std::stod(literal);
		dStream << dVal;
		cStream << static_cast<char>(dVal);
		iStream << static_cast<int>(dVal);
		fStream << static_cast<float>(dVal);
	}
	else {
		std::cout << "I dont know what you're talking about...\n";
		return;
	}
	std::cout << "char: " << ((cStream.str().size() == 1) ? "\'" + cStream.str() + "\'" : cStream.str()) << "\n";
	std::cout << "int: " << ((iStream.str().empty()) ? "impossible" : iStream.str()) << "\n";
	std::cout << "float: " << ((fStream.str().empty()) ? "impossible" : fStream.str() + "f") << "\n";
	std::cout << "double: " << ((dStream.str().empty()) ? "impossible" : dStream.str()) << "\n";

}