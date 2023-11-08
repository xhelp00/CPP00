#include "Phonebook.h"

int main(void)
{

	Phonebook		pho;
	std::string		str;

	while(str != "EXIT")
	{
		std::cout << "Enter ADD / SEARCH / EXIT > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			pho.add();
		else if (str == "SEARCH")
			pho.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return 0;
		}
	}	
	return 0;
}