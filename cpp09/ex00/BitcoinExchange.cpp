#include "BitcoinExchange.hpp"

static bool valiDate(int year, int month, int day) {
	if (day < 1 || day > 31)
		return false;
	if (month < 1 || month > 12)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			if (day > 29)
				return false;
		} else if (day > 28)
			return false;
	}
	return true;
}

static bool patternMatches(std::string input, std::regex pattern) {
	return std::regex_match(input, pattern);
}

static std::string trim(const std::string& string) {
	std::string whitespace = " \n\t\r";
	size_t start = string.find_first_not_of(whitespace);
	if (start == std::string::npos)
		return "";
	size_t end = string.find_last_not_of(whitespace);
	return string.substr(start, (end - start + 1));
}

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	_data = other._data;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this == &other) return *this;
	_data = other._data;
	return *this;
}

std::string BitcoinExchange::parseLine(const std::string& line, char delim, time_t& date, float& value) const {
	std::istringstream lineStream(line);
	std::string dateString;
	std::string valueString;
	if (line.find(delim) == std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);
	if (!getline(lineStream, dateString, delim) || !getline(lineStream, valueString))
		throw std::runtime_error("Error: bad input => " + line);
	dateString = trim(dateString);
	valueString = trim(valueString);
	if (dateString.empty())
		throw std::runtime_error("Error: bad input => " + line);
	date = parseDate(dateString);
	if (date == -1)
		throw std::runtime_error("Error: bad input => " + line);
	if (valueString.empty())
		throw std::runtime_error("Error: bad input => " + line);
	try {
		value = std::stof(valueString);
	} catch (std::invalid_argument& e) {
		throw std::runtime_error("Error: bad input => " + line);
	}
	return dateString;
}

time_t BitcoinExchange::parseDate(const std::string& dateString) const {
	std::istringstream iStream(dateString);
	int year;
	int month;
	int day;
	char delim;
	if (!(iStream >> year >> delim >> month >> delim >> day) || !iStream.eof() || iStream.fail())
		return -1;
	if (!valiDate(year, month, day))
		return -1;
	std::tm tm = {};
	tm.tm_year = year;
	tm.tm_mon = month;
	tm.tm_mday = day;
	return std::mktime(&tm);
}

float BitcoinExchange::getTotalValue(time_t date, float count) const {
	std::map<time_t, float>::const_iterator it;
	it = _data.find(date);
	if (it != _data.end())
		return count * it->second;
	it = _data.upper_bound(date);
	if (it != _data.begin())
		return count * std::prev(it)->second;
	throw std::runtime_error("Error: rates not available.");
}

void BitcoinExchange::initDatabase(const std::string& databaseFilePath) {
	std::ifstream database (databaseFilePath);
	if (!database.is_open() && !database.good())
		throw std::runtime_error("Error: could not open file.");
	database.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string line;
	time_t date;
	float value;
	while (getline(database, line)) {
		if (!patternMatches(line, std::regex(R"(^(\d{4})-(\d{2})-(\d{2}),-?(\d+(\.\d+)?)$)")))
			throw std::runtime_error("Error: bad input => " + line);
		parseLine(line, ',', date, value);
		_data[date] = value;
	}
}

void BitcoinExchange::calculateTotals(const std::string& inputFilePath) const {
	std::ifstream inputFile(inputFilePath);
	if (!inputFile.is_open() && !inputFile.good())
		throw std::runtime_error("Error: could not open file.");
	inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string line;
	time_t date;
	float count;
	float total;
	while (getline(inputFile, line)) {
		try {
			if (!patternMatches(line, std::regex(R"(^(\d{4})-(\d{2})-(\d{2}) \| -?(\d+(\.\d+)?)$)")))
				throw std::runtime_error("Error: bad input => " + line);
			line = parseLine(line, '|', date, count);
			if (count < 0)
				throw std::runtime_error("Error: not a positive number.");
			if (count > 1000)
				throw std::runtime_error("Error: too large a number.");
			total = getTotalValue(date, count);
			std::cout << line << " => " << count << " = " << total << "\n";
		} catch (std::runtime_error& e) {
			std::cout << e.what() << "\n";
		}
	}
}
