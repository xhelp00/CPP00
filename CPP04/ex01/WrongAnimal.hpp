#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal 
{
	protected:
				std::string _type;
	public:
				WrongAnimal();
				WrongAnimal(std::string type);
				WrongAnimal(const WrongAnimal& other);
				WrongAnimal& operator=(const WrongAnimal& other);
				~WrongAnimal();
				virtual void makeSound() const;
				virtual std::string getType() const;
};

#endif