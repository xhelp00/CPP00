#include "Phonebook.h"

Contact::Contact()
{

}

Contact::~Contact()
{

}
//set methods
void Contact::setFirstName(std::string str)
{
	this->_firstName = str;
}

void Contact::setLastName(std::string str)
{
	this->_lastName = str;
}

void Contact::setNickName(std::string str)
{
	this->_nickName = str;
}

void Contact::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
}

void Contact::setSecret(std::string str)
{
	this->_darkestSecret = str;
}

//get methods
std::string Contact::getFirstName() const
{
	return this->_firstName;
}

std::string Contact::getLastName() const
{
	return this->_lastName;
}

std::string Contact::getNickName() const
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}

std::string Contact::getSecret() const
{
	return this->_darkestSecret;
}

