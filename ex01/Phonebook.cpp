#include "Phonebook.h"

Phonebook::Phonebook()
{
	this->_index = 0;
}

Phonebook::~Phonebook()
{

}

/* 
Contact Phonebook::getContact(int index)
{
	return this->_contacts[_index % 8];
}
 */

void Phonebook::add()
{
	std::string str;

	str = "";
	if (this->_index > 7)
		std::cout << "You are about to replace " << this->_contacts[this->_index % 8].getFirstName() << " which is the oldest contact." << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a first name: ";
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
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}