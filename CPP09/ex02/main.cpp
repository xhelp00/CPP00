#include "PmergeMe.hpp"

int main(int ac, char*av[])
{
	if (ac < 2)
	{
		std::cout << "Not enough arguments" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe seq(ac - 1, av + 1);
		seq.showSorted();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		//std::cout << "ERROR" << std::endl;
	}
	return 0;
}