#include "HumanB.class.hpp"

# include "HumanB.class.hpp"
# include "Weapon.class.hpp"
# include <iostream>


HumanB::HumanB(std::string name) {
	this->_name = name;
}

HumanB::HumanB() {
	
}

HumanB::~HumanB() {

}

void HumanB::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon) {
	this->_weapon = weapon;
}