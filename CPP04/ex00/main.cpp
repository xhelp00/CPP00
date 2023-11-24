#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

const WrongAnimal* metawrong = new WrongAnimal();
const WrongAnimal* x = new WrongCat();
std::cout << x->getType() << " " << std::endl;
x->makeSound();
metawrong->makeSound();

delete i;
delete j;
delete x;
delete meta;
delete metawrong;

return 0;
}