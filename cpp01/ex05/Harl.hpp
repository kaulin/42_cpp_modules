#ifndef Class_HPP
#define Class_HPP

# define DEBUG_MSG "DEBUG"
# define INFO_MSG "INFO"
# define WARNING_MSG "WARNING"
# define ERROR_MSG "ERROR"

#include <iostream>

class Harl
{
private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
public:
	// Construct
	Harl();
	// Destroy
	~Harl();
	// Get
	// Set
	// Other
	void	complain(std::string level);
};

#endif