#include "Harl.hpp"

// Private
void	Harl::_debug(void) { std::cout << DEBUG_MSG << std::endl; }
void	Harl::_info(void) { std::cout << INFO_MSG << std::endl; }
void	Harl::_warning(void) { std::cout << WARNING_MSG << std::endl; }
void	Harl::_error(void) { std::cout << ERROR_MSG << std::endl; }

// Construct
Harl::Harl () {}
// Destruct
Harl::~Harl() {}
// Get
// Set
// Other
void	Harl::complain(std::string level) {
	void		(Harl::*functionArray[4])(void) = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
	std::string	levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++) {
		if (level == levelArray[i]) (this->*functionArray[i])();
	}
}