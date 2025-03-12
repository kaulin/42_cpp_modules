#include "RPN.hpp"

RPN::RPN () {}
RPN::RPN(const RPN& other) : _numbers(other._numbers) {}
RPN::~RPN() {}
RPN& RPN::operator=(const RPN& other) {
	if (this == &other) return *this;
	_numbers = other._numbers;
	return *this;
}

void RPN::handleOperation(char op) {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers in stack");
	long top = _numbers.top();
	_numbers.pop();
	long second = _numbers.top();
	_numbers.pop();
	long result;
	switch (op)
	{
	case '*':
		result = second * top;
		break;
	case '+':
		result = second + top;
		break;
	case '-':
	result = second - top;
		break;
	case '/':
	result = second / top;
		break;
	default:
		throw std::runtime_error("Unknown token");
		break;
	}
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
		throw std::runtime_error("Operation overflowed");
	else
		_numbers.push(result);
}

void RPN::processToken(const std::string& token) {
	if (token.size() > 1)
		throw std::runtime_error("Token too large: " + token);
	if (std::isdigit(token[0]))
		_numbers.push(std::stoi(token));
	else
		handleOperation(token[0]);
}

int RPN::process(const std::string& expression) {
	if (expression.empty())
		throw std::runtime_error("Incomplete expression");
	std::istringstream input(expression);
	std::string token;
	while (!input.eof()) {
		input >> token;
		processToken(token);
	}
	if (_numbers.size() != 1)
		throw std::runtime_error("Incomplete expression");
	int result = _numbers.top();
	_numbers.pop();
	return result;
}

void RPN::printNumbers() const {
	std::stack<int> copy(_numbers);
	while(!copy.empty()) {
		std::cout << copy.top();
		copy.pop();
	}
	std::cout << "\n";
}