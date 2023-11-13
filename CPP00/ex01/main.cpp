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

// helper method using iomanip to set width, right alingment and cutting string if too long
void printColumn(const std::string& text)
{
	if (text.size() > 9)
		std::cout << std::setw(10) << std::right << text.substr(0, 8) + ".";
	else 
		std::cout << std::setw(10) << std::right << text;
}

// method counting contacts and printing them in formated manner
int	count(Contact contacts[8])
{
	char		c;
	int			i;
	std::string	str;
	
	c = '0';
	i = 0;
	while (++c <= '8')
		if (contacts[c - 1 - '0'].getFirstName().size())
		{
			str = c;
			std::cout << "|";
			printColumn(str);
			std::cout << "|";
			printColumn(contacts[c - 1 - '0'].getFirstName());
			std::cout << "|";
			printColumn(contacts[c - 1 - '0'].getLastName());
			std::cout << "|";
			printColumn(contacts[c - 1 - '0'].getNickName());
			std::cout << "|" << std::endl;
			++i;
		}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	return (i);
}
