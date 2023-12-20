#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return *this;
}

Intern::~Intern()
{}

// Functions to create specific forms
static AForm	*new_robo(std::string target)
{
	AForm	*robo = new RobotomyRequestForm(target);
	return (robo);
}

static AForm	*new_president(std::string target)
{
	AForm	*president = new PresidentialPardonForm(target);
	return (president);
}

static AForm	*new_shrub(std::string target)
{
	AForm	*shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm	*(*functions[3])(std::string target) = { new_robo, new_president, new_shrub};
	std::string	options[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm	*pointer = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (name == options[i])
			pointer = functions[i](target);
	}
	if (pointer)
		std::cout << "Intern creates " << *pointer << std::endl;
	else
		throw (Intern::UnknownException());
	return (pointer);
}

const char*			Intern::UnknownException::what(void) const throw()
{
	return ("Unknown form. Creation failed!");
}