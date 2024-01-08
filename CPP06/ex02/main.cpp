#include "Identify.hpp"

void	sectionTitle(const std::string& title)
{
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

int main(void)
{
	
	srand((unsigned) time(NULL));

	sectionTitle("Generated 3 random classes");
	std::cout << "First class ";
	Base *base1 = generate();
	std::cout << "Second class ";
	Base *base2 = generate();
	std::cout << "Third class ";
	Base *base3 = generate();

	sectionTitle("Checking first class");
	identify(base1);
	identify(*base1);

	sectionTitle("Checking second class");
	identify(base2);
	identify(*base2);

	sectionTitle("Checking third class");
	identify(base3);
	identify(*base3);
	
	sectionTitle("Cleanup");
	delete base1;
	delete base2;
	delete base3;

	return 0;

}