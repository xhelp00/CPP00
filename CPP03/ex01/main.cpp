#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	//ClapTrap Rubbish("Rubbish");
	ScavTrap Crap("Crap");

	//std::cout << Rubbish.getName() << "'s status: " << Rubbish.getHp() << " HP | " << Rubbish.getEnergy() << " Energy" << std::endl;
	//std::cout << Crap.getName() << "'s status: " << Crap.getHp() << " HP | " << Crap.getEnergy() << " Energy" << std::endl;

	ScavTrap Scavanger("Scavanger");
	Scavanger.attack("Crap");
	Crap.takeDamage(Scavanger.getAttack());
	Scavanger.guardGate();

	std::cout << Crap.getName() << "'s status: " << Crap.getHp() << " HP | " << Crap.getEnergy() << " Energy" << std::endl;
	std::cout << Scavanger.getName() << "'s status: " << Scavanger.getHp() << " HP | " << Scavanger.getEnergy() << " Energy" << std::endl;

	return 0;
}