#include "HumanB.class.hpp"

# include "HumanB.class.hpp"
# include "Weapon.class.hpp"
# include <iostream>


HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
}

/*HumanB::HumanB() {
	
}*/

HumanB::~HumanB() {

}

void HumanB::attack() {
	std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}