#include "Cat.hpp"


Cat::Cat(): Animal()
{
	this->_type = "Cat";
}

Cat::Cat(std::string type): Animal(type)
{
	this->_type = type;
	std::cout << this->_type << " has been created by calling constructor." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "Copy Cat constructor called." << std::endl;

	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Copy Cat assignment operator called." << std::endl;
	this->_type = other._type;

	return *this;
}

Cat::~Cat()
{
	std::cout << this->_type << " has been destroyed by calling destructor." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << this->_type << " says meow." << std::endl;
}

/* std::string Cat::getType() const
{
	return this->_type;
} */
