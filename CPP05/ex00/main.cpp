#include "Bureaucrat.hpp"

void	sectionTitle(const std::string& title)
{
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

int	main() {
	sectionTitle("Constructor test");

	try {
		Bureaucrat	minister("minister", 1);
		std::cout << minister;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	test("test", -42);
		std::cout << test;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}


	try {
		Bureaucrat	test("test", 4242);
		std::cout << test;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	sectionTitle("Increment test");

	try {
		Bureaucrat	minister("minister", 12);
		std::cout << minister;
		minister.gradeUp(10);
		std::cout << minister;
		minister.gradeUp(1);
		std::cout << minister;
		minister.gradeUp(1); // too high!
		std::cout << minister;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	sectionTitle("Decrement test");

	try {
		Bureaucrat	minister("minister", 139);
		std::cout << minister;
		minister.gradeDown(10);
		std::cout << minister;
		minister.gradeDown(1);
		std::cout << minister;
		minister.gradeDown(1); // too low!
		std::cout << minister;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}