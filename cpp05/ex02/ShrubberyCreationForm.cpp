#include "ShrubberyCreationForm.hpp"

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("ShrubberyCreationForm", 145, 137), 
	_target("TARGET") {
	std::cout << "ShrubberyCreationForm: Default constructor called." << std::endl;
}
// Parameterized Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :  
	AForm("ShrubberyCreationForm", 145, 137), 
	_target(target) {
	std::cout << "ShrubberyCreationForm: Parameterized constructor called." << std::endl;
	if (target.length() == 0) throw std::invalid_argument("empty name");
}
// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :  
	AForm("ShrubberyCreationForm", 145, 137), 
	_target(other._target) {
	std::cout << "ShrubberyCreationForm: Copy constructor called." << std::endl;
}
// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: Destructor called." << std::endl;
}
// Copy Assignment Operators
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm: Copy assignment operator called." << std::endl;
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
	if (!outfile) { std::cout << "Missing permission of the landowner to plant a shrubbery at " << _target << "\n"; }
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