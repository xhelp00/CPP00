#include "Phonebook.h"

Phonebook::Phonebook()
{
	this->_index = 0;
	std::cout << "+---------------------------------------------------------+" << std::endl;
	std::cout << "|  Welcome to the 80s and their unbelievable technology!  |" << std::endl;
	std::cout << "+---------------------------------------------------------+" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "¯\\_(ツ)_/¯" << std::endl;
}

void Phonebook::add()
{
	std::string str;

	str = "";
	if (this->_index > 7)
		std::cout << "You are about to replace " << this->_contacts[this->_index % 8].getFirstName() << " which is the oldest contact." << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setFirstName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setLastName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter nickname: "; 
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setNickName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter phone number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setPhoneNumber(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[this->_index % 8].setSecret(str);
			std::cout << this->_contacts[this->_index % 8].getFirstName() << " successfully added." <<  std::endl;
		}
	}
	this->_index++;
}

void Phonebook::search()
{
	
	std::string	str;

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;

	if (!count(this->_contacts))
	{
		std::cout << std::endl << "¯\\_(ツ)_/¯ Phonebook is empty! ¯\\_(ツ)_/¯" << std::endl;
		return ;
	}

	while (!std::cin.eof())
	{
		std::cout << "Select index for details: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && this->_contacts[str[0] - 1 - '0'].getFirstName().size())
				break ;
		}
		if (str != "")
			std::cout << "¯\\_(ツ)_/¯ Invalid index! ¯\\_(ツ)_/¯" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->_contacts[str[0] - 1 - '0']);
}

void	Phonebook::print(Contact contact)
{
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getSecret() << std::endl;
}