#include "Zombie.class.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void) {
	// init via constructor - on the stack
	//Zombie foo = Zombie("Foo");
	//foo.announce();

	Zombie *horde = zombieHorde(42, "clone");
	
	delete [] horde;

	return 0;
}