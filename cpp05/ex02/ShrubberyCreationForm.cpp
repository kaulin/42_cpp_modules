#include "ShrubberyCreationForm.hpp"

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("ShrubberyCreationForm", 145, 137), 
	_target("TARGET") {
	std::cout << "ShrubberyCreationForm: Default constructor called.\n";;
}
// Parameterized Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :  
	AForm("ShrubberyCreationForm", 145, 137), 
	_target(target) {
	std::cout << "ShrubberyCreationForm: Parameterized constructor called.\n";;
	if (target.length() == 0) throw std::invalid_argument("empty string");
}
// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :  
	AForm(other), 
	_target(other._target) {
	std::cout << "ShrubberyCreationForm: Copy constructor called.\n";;
}
// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: Destructor called.\n";;
}
// Copy Assignment Operators
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm: Copy assignment operator called.\n";;
	if (this == &other) return *this;
	return *this;
}
// Getters
// Setters
// Other
void ShrubberyCreationForm::_implementEnactment() const {
	std::string path = _target + "_shrubbery";
	std::ofstream outfile;
	outfile.open(path);
	if (!outfile) throw std::runtime_error("local council has filed a complaint about shrubbery price and the district court has revoked planting permissions until the case is reviewed");
	else {
		outfile << "               ,@@@@@@@,\n";
		outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
		outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
		outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
		outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
		outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
		outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
		outfile << "       |o|        | |         | |\n";
		outfile << "       |.|        | |         | |\n";
		outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	}
}