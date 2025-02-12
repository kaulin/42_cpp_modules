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
	if (literal == "-inff" || literal == "+inff")
		return true;
	std::istringstream inputstream(literal.substr(0, literal.size() -1));
	float f;
	inputstream >> f;
	return inputstream.eof() && !inputstream.fail();
}

bool isDouble(const std::string& literal) {
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
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

	if (isChar(literal)) {
		cVal = literal[0];
		cStream << "\'" << cVal << "\'";
		iStream << static_cast<int>(cVal);
		fStream << std::fixed << std::setprecision(1) << static_cast<float>(cVal);
		dStream << std::fixed << std::setprecision(1) << static_cast<double>(cVal);
	}

	else if (isInt(literal)) {
		iVal = std::stoi(literal);
		iStream << iVal;
		if (iVal >= 0 && iVal <= 127) {
			if (!std::isprint(iVal))
				cStream << "Not displayable";
			else 
				cStream << "\'" << static_cast<char>(iVal) << "\'";
		}
		fStream << static_cast<float>(iVal);
		dStream << static_cast<double>(iVal);
	}

	else if (isFloat(literal)) {
		fVal = std::stof(literal);
		fStream << fVal;
		if (fVal >= 0 && fVal <= 127) {
			if (!std::isprint(fVal))
				cStream << "Not displayable";
			else 
				cStream << "\'" << static_cast<char>(fVal) << "\'";
		}
		if (fVal >= -2147483648.0f && fVal < 2147483647.0f)
			iStream << static_cast<int>(fVal);
		dStream << static_cast<double>(fVal);
	}

	else if (isDouble(literal)) {
		dVal = std::stod(literal);
		dStream << dVal;
		if (dVal >= 0 && dVal <= 127) {
			if (!std::isprint(dVal))
				cStream << "Not displayable";
			else 
				cStream << "\'" << static_cast<char>(dVal) << "\'";
		}
		if (dVal >= std::numeric_limits<int>::min() && dVal <= std::numeric_limits<int>::max())
			iStream << static_cast<int>(dVal);
		if (literal == "+inf" || literal == "-inf" || literal == "nan" || (dVal >= std::numeric_limits<float>::lowest() && dVal <= std::numeric_limits<float>::max()))
			fStream << static_cast<float>(dVal);
	}

	std::cout << "char: " << ((cStream.str().empty()) ? "impossible" : cStream.str()) << "\n";
	std::cout << "int: " << ((iStream.str().empty()) ? "impossible" : iStream.str()) << "\n";
	std::cout << "float: " << ((fStream.str().empty()) ? "impossible" : fStream.str() + "f") << "\n";
	std::cout << "double: " << ((dStream.str().empty()) ? "impossible" : dStream.str()) << "\n";
}