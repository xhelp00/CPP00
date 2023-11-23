#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
				Brain *_brain;
	public:
				Dog();
				Dog(std::string type);
				Dog(const Dog& other);
				Dog& operator=(const Dog& other);
				~Dog();
				void makeSound() const;
				void readBrain() const;
};

#endif