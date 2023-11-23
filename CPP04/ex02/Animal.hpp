#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal 
{
	protected:
				std::string _type;
	public:
				Animal();
				Animal(std::string type);
				Animal(const Animal& other);
				Animal& operator=(const Animal& other);
				virtual ~Animal();
				virtual void makeSound() const = 0; // need to declare at least one pure virtual function within the class
													//from standard 11 derived classes use keyword "override" when using this function
				virtual std::string getType() const;
				virtual void readBrain() const;
};

#endif