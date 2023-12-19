#include "Bureaucrat.hpp"

void	sectionTitle(const std::string& title)
{
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

int	main() {
	sectionTitle("Constructor test");

	try
	{
		Bureaucrat	minister("minister", 1);
		std::cout << minister;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	test("test", -42);
		std::cout << test;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	test("test", 4242);
		std::cout << test;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	sectionTitle("Increment test");
	try
	{
		Bureaucrat	minister("minister", 12);
		std::cout << minister;
		minister.gradeUp(10);
		std::cout << minister;
		minister.gradeUp(1);
		std::cout << minister;
		minister.gradeUp(1); // too high!
		std::cout << minister;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	sectionTitle("Decrement test");
	try
	{
		Bureaucrat	minister("minister", 139);
		std::cout << minister;
		minister.gradeDown(10);
		std::cout << minister;
		minister.gradeDown(1);
		std::cout << minister;
		minister.gradeDown(1); // too low!
		std::cout << minister;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	sectionTitle("Create and sign Form test");
	try
	{
		Form form2("uselss", 150, 150);
		std::cout << form2;
		Form form3(form2);
		std::cout << form3;
		Form form4("more useless", 100, 100);
		std::cout << form4;
		//Form form5("more useless", -42, 100);
		//std::cout << form5;
		Bureaucrat	minister("minister", 139);
		std::cout << minister;
		minister.signForm(form2);
		std::cout << form2;
		minister.signForm(form4);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	sectionTitle("Double Sign test");
	try
	{
		Form form2("uselss", 150, 150);
		std::cout << form2;
		Bureaucrat	minister("minister", 139);
		std::cout << minister;
		minister.signForm(form2);
		std::cout << form2;
		minister.signForm(form2);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

}