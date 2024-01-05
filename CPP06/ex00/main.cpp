#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./Conversion [input]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
}