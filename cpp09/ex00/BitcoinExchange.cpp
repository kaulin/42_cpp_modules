#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange () {
	std::ifstream database (DATABASE);
	std::string year;
	std::string month;
	std::string day;
	std::string value;
	database.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (getline(database, year, '-') && getline(database, month, '-') && getline(database, day, ',') && getline(database, value)) {
		time_t date;
		std::tm tm = {};
		tm.tm_year = std::stoi(year);
		tm.tm_mon = std::stoi(month);
		tm.tm_mday = std::stoi(day);
		date = std::mktime(&tm);
		_data[date] = std::stof(value);
		std::cout << "Inserted KEY " << date << " VALUE " << value << "\n";
	}
	database.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	_data = other._data;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this == &other) return *this;
	_data = other._data;
	return *this;
}

void BitcoinExchange::calculateTotals(const std::string& inputFilePath) const {
	std::ifstream inputFile(inputFilePath);
	std::string line;
	while (getline(inputFile, line)) {
		try {
			validate(line);
			calculate(line);
			// _data.lower_bound(target)!!!!
		}
	}
}

void BitcoinExchange::addData(const std::string& dataString) {
	(void)dataString;
}
