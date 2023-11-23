#include "Dog.hpp"


Dog::Dog(): Animal()
{
	this->_type = "Dog";
}

Dog::Dog(std::string type): Animal(type)
{
	this->_type = type;
	std::cout << this->_type << " has been created by calling constructor." << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "Copy Dog constructor called." << std::endl;

	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Copy Dog assignment operator called." << std::endl;
	this->_type = other._type;

	return *this;
}

Dog::~Dog()
{
	std::cout << this->_type << " has been destroyed by calling destructor." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->_type << " says wof." << std::endl;
}

/* std::string Dog::getType() const
{
	return this->_type;
} */