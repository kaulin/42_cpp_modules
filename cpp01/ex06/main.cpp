#include "Harl.hpp"

void	harlFilter(std::string filter) {
	Harl	harl;
	int		level = 0;
	std::string	levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (filter != levelArray[level] && level < 4) level++;
	switch (level)
	{
	case 0:
		while (level < 4) harl.complain(levelArray[level++]);
		break;
	case 1:
		while (level < 4) harl.complain(levelArray[level++]);
		break;
	case 2:
		while (level < 4) harl.complain(levelArray[level++]);
		break;
	case 3:
		while (level < 4) harl.complain(levelArray[level++]);
		break;
	default:
		level = 0;
		while (level < 4) harl.complain(levelArray[level++]);
		break;
	}
}

int	main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "I seek an argument!" << std::endl;
		return 2;
	}
	harlFilter(std::string(argv[1]));
	return 0;
}