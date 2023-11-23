#include "Animal.hpp"

Animal::Animal()
{}

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << "Animal " << this->_type << " has been created by calling constructor." << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy Animal constructor called." << std::endl;

	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Copy Animal assignment operator called." << std::endl;
	this->_type = other._type;

	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << this->_type << " has been destroyed by calling destructor." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal " << this->_type << " has made unspecific sound." << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::readBrain() const
{

}