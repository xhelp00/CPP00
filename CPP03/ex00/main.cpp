#include "ClapTrap.hpp"

int main()
{
	ClapTrap Petr("Petr");
	ClapTrap test(Petr);
	test.setName("test");
	Petr.attack("droid");
	test.takeDamage(5);
	

	return 0;
}