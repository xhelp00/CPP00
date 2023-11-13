#ifndef HUMANB_CLASS_HPP
#define HUMANB_CLASS_HPP

# include <string>
# include "Weapon.class.hpp"

class HumanB {

private:
			std::string _name;
			Weapon _weapon;

public:
			HumanB(std::string name);
			HumanB();
			~HumanB();
			void attack();
			void setWeapon(Weapon weapon);

};

#endif
