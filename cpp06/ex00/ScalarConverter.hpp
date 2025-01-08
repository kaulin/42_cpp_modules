#pragma once

#include <iostream>

class ScalarConverter {
	private:
		// Default Constructor
		ScalarConverter();
		// Copy Constructor
		ScalarConverter(const ScalarConverter& other);
		// Destructor
		~ScalarConverter();
		// Copy Assignment Operator
		ScalarConverter& operator=(const ScalarConverter& other);
	public:
		static void convert(const std::string& literal);
};