#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
				std::string		_name;
				unsigned int	_hp;
				unsigned int	_energy;
				unsigned int	_attack;

	public:
				ClapTrap(std::string name);
				ClapTrap(const ClapTrap& other);
				ClapTrap& operator=(const ClapTrap& other);
				~ClapTrap();
				void setName(std::string name);
				void attack(const std::string& target);
				void takeDamage(unsigned int amount);
				void beRepaired(unsigned int amount);

};

#endif