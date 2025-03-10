#pragma once

#include <map>
#include <ctime>
#include <iostream>
#include <fstream>
#include <limits>

#define DATABASE "./data.csv"

class BitcoinExchange {
private:
	std::map<time_t, float> _data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);

	void calculateTotals(const std::string& inputFilePath) const;
	void addData(const std::string& dataString);
	
	class BitcoinExchangeException : public std::exception {};
};