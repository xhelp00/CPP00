#include "Zombie.class.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << this->_name << " was created." << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->_name << " was destroyed." << std::endl;

}

void Zombie::announce(void) {
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
