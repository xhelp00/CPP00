#include "WrongCat.hpp"


WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
	this->_type = type;
	std::cout << this->_type << " has been created by calling constructor." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << "Copy WrongCat constructor called." << std::endl;

	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Copy WrongCat assignment operator called." << std::endl;
	this->_type = other._type;

	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << this->_type << " has been destroyed by calling destructor." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << this->_type << " says Don't touch my garbage code!" << std::endl;
}

/* std::string WrongCat::getType() const
{
	return this->_type;
} */
