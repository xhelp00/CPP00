#include "Brain.hpp"

Brain::Brain()
{
	this->_ideas = setIdeas();
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& other)
{
	//delete[] this->_ideas;
	this->_ideas = new std::string[100];

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Copy " + other._ideas[i];

	std::cout << "Brain copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	delete[] this->_ideas;
	this->_ideas = new std::string[100];

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Assigned " + other._ideas[i];

	std::cout << "Brain copy assignment operator called." << std::endl;
	return *this;
}

Brain::~Brain()
{
	delete[] this->_ideas;
	std::cout << "Brain destructor called." << std::endl;

}

std::string *Brain::setIdeas()
{
	std::string *ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << "idea no. " << i+1;
		ideas[i] = ss.str();
	}		
	return ideas;
}

std::string *Brain::getIdeas() const
{
	return this->_ideas;
}