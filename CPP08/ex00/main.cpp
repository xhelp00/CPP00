#include "easyfind.hpp"
#include <cstdlib>		// For rand() and srand()
#include <ctime>		// For time()

int	main(void)
{
	std::vector<int> vec;

	// Seed the random number generator
	srand(static_cast<unsigned int>(time(NULL)));

	// Adding random numbers to the vector
	for (int i = 0; i < 10; ++i) {
		vec.push_back(rand() % 100); // Random numbers between 0 and 99
	}

	// Print the vector using an iterator
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	//test easyfind part
	try
	{
		{::easyfind(vec, 42);}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
return 0;
}