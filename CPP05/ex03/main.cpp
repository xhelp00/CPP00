#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <unistd.h> 

void	sectionTitle(const std::string& title)
{
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

int	main()
{
	sectionTitle("Intern test make form");
	Intern noob;
	AForm* test;

	try
	{
		test = noob.makeForm("robotomy request", "Bender");
		std::cout << *test << std::endl;
		test = noob.makeForm("presidential pardon", "Arthur Dent");
		test = noob.makeForm("shrubbery creation", "garden");
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	sectionTitle("Intern test make unknown form");
	try
	{
		test = noob.makeForm("resignation letter", "employee");
		std::cout << *test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}