#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./Bitcoin <input_file>" << std::endl;
		return 1;
	}
	else
	{
		Bitcoin btc;
		btc.read_file(av[1]);
	}
	return 0;
}