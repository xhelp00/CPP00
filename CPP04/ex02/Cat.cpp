#include "Cat.hpp"


Cat::Cat(): Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(std::string type): Animal(type)
{
	this->_type = type;
	_brain = new Brain();
	std::cout << this->_type << " has been created by calling constructor." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	_brain = NULL;	
	_type = other._type;
	// if other._brain exist
	if (other._brain)
		_brain = new Brain(*other._brain);
	*this = other;
	std::cout << "Copy Cat constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	Animal::operator=(other);
	this->_type = other._type;
	*_brain = *other._brain;

	std::cout << "Copy Cat assignment operator called." << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << this->_type << " has been destroyed by calling destructor." << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << this->_type << " says meow." << std::endl;
}

void Cat::readBrain() const
{
	std::string *catbrain = _brain->getIdeas();
	std::cout << "Cat's brain at address " << _brain << " contains: " << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (catbrain[i].empty())
			break ;
		std::cout << catbrain[i] << " ";
	}
		std::cout << std::endl;
		std::cout << std::endl;
}
