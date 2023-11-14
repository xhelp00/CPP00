#include "Harl.class.hpp"
#include <iostream>

int main(int ac, char **av)
{
	Harl harl;
	
	if (ac != 2){
		std::cerr << "Error.\nInvalid number of arguments\nUse: ./harlFilter LEVEL" << std::endl;
		return 1;
	}
	int	level = harl.getLevel(av[1]);
	switch (level)
	{
		case 0:
			harl.complain("DEBUG");
			//fall through
		case 1:
			harl.complain("INFO");
			//fall through
		case 2:
			harl.complain("WARNING");
			//fall through
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "[ INVALID ] \nProbably complaining about insignificant problems." << std::endl;
			break ;
	}

	return 0;
}
