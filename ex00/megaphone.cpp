#include <iostream>
#include <string>

std::string makeUpper(const std::string& input)
{
	std::string output;
	for (std::string::size_type i = 0; i < input.size(); i++)
	{
		output += std::toupper(input[i]);
	}
	return output;
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOAD AND UNBERABLE FEEDBACK NOISE *";

	for(int i = 1; i < ac; i++)
	{
		std::string myString = av[i];
		std::string newString = makeUpper(myString);
		std::cout << newString;
	}
	std::cout << std::endl;
	return 0;
}
