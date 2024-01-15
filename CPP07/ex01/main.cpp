#include "Iter.hpp"

void times_two(int const &n) 
{
	std::cout << n * 2 << std::endl;
}

void print(std::string const &s) 
{
	std::cout << s << std::endl;
}

int main(void) 
{
	int array[] = {1, 2, 3, 4, 5};
	std::cout << "Calling iter using multiply function on array of ints" << std::endl;
	::iter(array, 5, times_two);
	
	
	std::cout << "Calling iter using print function on array of strings" << std::endl;
	std::string strings[] = {"Hello", "42", "Prague"};
	::iter(strings, 3, print);
}