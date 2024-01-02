#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <unistd.h> 
#include <cstdlib>

void	sectionTitle(const std::string& title)
{
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

int	main()
{
	sectionTitle("test execution not signed");

	//This ensures the random number generator is seeded once when the program starts.
	srand((unsigned) time(NULL));
	
	try
	{
		Bureaucrat	minister("minister", 1);
		ShrubberyCreationForm shru("form");
		
		std::cout << minister;
		std::cout << shru;
		shru.execute(minister);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	sectionTitle("test execution with low level");
	try
	{
		Bureaucrat	minister("minister", 142);
		ShrubberyCreationForm shru("form");
		
		std::cout << minister;
		shru.beSigned(minister);
		std::cout << shru;
		shru.execute(minister);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	sectionTitle("test execution");
	try
	{
		Bureaucrat	minister("minister", 1);
		ShrubberyCreationForm shru("form");
		RobotomyRequestForm robo("dummy");
		
		std::cout << minister;
		std::cout << shru;
		std::cout << robo;
		robo.beSigned(minister);
		shru.beSigned(minister);
		shru.execute(minister);
		robo.execute(minister);

		RobotomyRequestForm robo2("dummy2");
		robo2.beSigned(minister);
		robo2.execute(minister);

		RobotomyRequestForm robo3("dummy3");
		robo3.beSigned(minister);
		robo3.execute(minister);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	sectionTitle("president execution");
	try
	{
		Bureaucrat	minister("minister", 1);
		PresidentialPardonForm pardon("Evaluator");
		
		
		std::cout << minister;
		std::cout << pardon;
	
		pardon.beSigned(minister);
		pardon.execute(minister);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}