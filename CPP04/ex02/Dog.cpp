#include "Dog.hpp"


Dog::Dog(): Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(std::string type): Animal(type)
{
	this->_type = type;
	_brain = new Brain();
	std::cout << this->_type << " has been created by calling constructor." << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
	_brain = NULL;	
	_type = other._type;
	// if other._brain exist
	if (other._brain)
		_brain = new Brain(*other._brain);
	*this = other;
	std::cout << "Copy Dog constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	Animal::operator=(other);
	this->_type = other._type;
	*_brain = *other._brain;

	std::cout << "Copy Dog assignment operator called." << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << this->_type << " has been destroyed by calling destructor." << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << this->_type << " says meow." << std::endl;
}

void Dog::readBrain() const
{
	std::string *Dogbrain = _brain->getIdeas();
	std::cout << "Dog's brain at address " << _brain << " contains: " << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (Dogbrain[i].empty())
			break ;
		std::cout << Dogbrain[i] << " ";
	}
		std::cout << std::endl;
		std::cout << std::endl;
}
