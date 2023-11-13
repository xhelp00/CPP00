#include "Zombie.class.hpp"

Zombie* newZombie(std::string name);

void randomChump( std::string name );

int main(void) {
	// init via constructor - on the stack
	Zombie foo = Zombie("Foo");
	foo.announce();

	// init class calling randomChump - on the stack
	randomChump("Random");

	// init class on the heap - manual memory management
	Zombie *zomb = newZombie("Pointed");
	zomb->announce();
	delete(zomb);
	
	return 0;
}