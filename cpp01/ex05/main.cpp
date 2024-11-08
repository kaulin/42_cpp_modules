#include "Harl.hpp"

int	main()
{
	Harl	harl;

	harl.complain("");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("NONSENSE");

	return 0;
}