#include "RobotomyRequestForm.hpp"

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm() : 
	AForm("RobotomyRequestForm", 72, 45), 
	_target("TARGET") {
	std::cout << "RobotomyRequestForm: Default constructor called." << std::endl;
}
// Parameterized Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :  
	AForm("RobotomyRequestForm", 72, 45), 
	_target(target) {
	std::cout << "RobotomyRequestForm: Parameterized constructor called." << std::endl;
	if (target.length() == 0) throw std::invalid_argument("empty name");
}
// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :  
	AForm("RobotomyRequestForm", 72, 45), 
	_target(other._target) {
	std::cout << "RobotomyRequestForm: Copy constructor called." << std::endl;
}
// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm: Destructor called." << std::endl;
}
// Copy Assignment Operators
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "RobotomyRequestForm: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	return *this;
}
// Getters
// Setters
// Other
void RobotomyRequestForm::_implementEnactment() const {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0,1);
	bool outcome = distribution(generator);
	std::cout << _target << ((outcome) ? " has been robotomized!\n" : "'s robotomy failed!\n");
}