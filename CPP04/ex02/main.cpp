#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	}
	//stepans tests
	{
	const Animal* dog1 = new Dog();
	const Animal* dog2 = new Dog();
	Dog	dog3;
	Dog	dog4(dog3);
	Dog	dog5;
	dog5 = dog3;
	const Animal* cat1 = new Cat();
	const Animal* cat2 = new Cat();
	Cat	cat3;
	Cat	cat4(cat3);
	Cat	cat5;		
	cat5 = cat3;
	
	//this will read brains of all the animals amd shows the memory address of the brain
	//to check if the brain is unique for each animal - that its not a shallow copy
	std::cout << std::endl;
	std::cout << "Reading brains ... " << std::endl;
	dog1->readBrain();
	dog2->readBrain();
	dog3.readBrain();
	dog4.readBrain();
	dog5.readBrain();
	cat1->readBrain();
	cat2->readBrain();
	cat3.readBrain();
	cat4.readBrain();
	cat5.readBrain();


	std::cout << std::endl;
	std::cout << "Creating array of animals ..." << std::endl;
	const Animal* animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();
	
	std::cout << std::endl;
	std::cout << "Reading brains of animals ..." << std::endl;
	animals[0]->readBrain();
	animals[1]->readBrain();
	animals[2]->readBrain();
	animals[3]->readBrain();

	std::cout << std::endl;
	std::cout << "Destructing array of animals ..." << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];
		
	std::cout << std::endl;
	std::cout << "Destructing ..." << std::endl;
	delete dog1;
	delete dog2;
	delete cat1;
	delete cat2;

	}
	
	return 0;
}