#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << "WrongAnimal " << this->_type << " has been created by calling constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy WrongAnimal constructor called." << std::endl;

	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "Copy WrongAnimal assignment operator called." << std::endl;
	this->_type = other._type;

	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << this->_type << " has been destroyed by calling destructor." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal " << this->_type << " has made unspecific wrong sound." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}