#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <regex>
#include <limits>

class RPN {
private:
	std::stack<int> _numbers;
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
public:
	RPN();
	~RPN();
	void printNumbers() const;
	void handleOperation(char op);
	void processToken(const std::string& token);
	int process(const std::string& expression);
};