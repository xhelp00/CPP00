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
			__attribute__((fallthrough));
		case 1:
			harl.complain("INFO");
			__attribute__((fallthrough));
		case 2:
			harl.complain("WARNING");
			__attribute__((fallthrough));
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "[ INVALID ] \nProbably complaining about insignificant problems." << std::endl;
			break ;
	}

	return 0;
}
