# include "HumanA.class.hpp"
# include "Weapon.class.hpp"
# include <iostream>


HumanA::HumanA(std::string name, Weapon weapon) {
	this->_name = name;
	this->_weapon = weapon;
}

HumanA::HumanA() {

}

HumanA::~HumanA() {

}

void HumanA::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}