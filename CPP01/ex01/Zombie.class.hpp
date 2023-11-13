#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP

# include <string>
# include <iostream>

class Zombie {

private:
			std::string _name;

public:
			Zombie(std::string name);
			Zombie();
			~Zombie();
			void announce( void );
			void setName(std::string n);

};

#endif
