#include "Harl.class.hpp"
#include <iostream>

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou did not put enough bacon in my burger!\nIf you did, I would not be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
 std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void )
{
 std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string level )
{

	int	num = getLevel(level);
	if (num == -1){
		std::cout << "[INVALID] \nProbably complaining about insignificant problems.\n" << std::endl;
		return ;
	}
	function_p	levels[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	(this->*(levels[num]))();

}

int	Harl::getLevel(std::string level)
{
	std::string	commands[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++){
		if (!level.compare(commands[i]))
			return (i);
	}
	return (-1);
}