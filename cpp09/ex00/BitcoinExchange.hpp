#pragma once

#include <map>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <exception>
#include <regex>

#define DATABASE "./data.csv"

class BitcoinExchange {
private:
	std::map<time_t, float> _data;
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	std::string parseLine(const std::string& line, char delim, time_t& date, float& value) const;
	time_t parseDate(const std::string& dateString) const;
	float getTotalValue(time_t date, float count) const;
public:
	BitcoinExchange();
	~BitcoinExchange();
	void initDatabase(const std::string& databaseFilePath);
	void calculateTotals(const std::string& inputFilePath) const;
};