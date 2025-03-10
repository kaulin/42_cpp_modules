#pragma once

#include <iostream>

class BitcoinExchange {
private:
	std::string	_name;
public:
	// Default Constructor
	BitcoinExchange();
	// Parameterized Constructor
	BitcoinExchange(const std::string& name);
	// Copy Constructor
	BitcoinExchange(const BitcoinExchange& other);
	// Destructor
	~BitcoinExchange();
	// Copy Assignment Operator
	BitcoinExchange& operator=(const BitcoinExchange& other);

	// Getters
	const std::string&	getName() const;
	// Setters
	void		setName(std::string _name);
	// Other
};