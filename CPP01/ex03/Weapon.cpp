#include "Weapon.class.hpp"
#include <iostream>

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::Weapon() {

}

Weapon::~Weapon() {
	
}

void Weapon::setType(std::string type) {
	this->_type = type;
}

const std::string &Weapon::getType() {
	std::string &ref = _type;
	return ref;
}