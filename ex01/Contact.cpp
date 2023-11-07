#include "Phonebook.h"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void Contact::setContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string sec)
{
	this->_firstName = fn;
	this->_lastName = ln;
	this->_nickName = nn;
	this->_phoneNumber = pn;
	this->_darkestSecret = sec;
}


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

