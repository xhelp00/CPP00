#ifndef HUMANA_CLASS_HPP
#define HUMANA_CLASS_HPP

# include <string>
# include "Weapon.class.hpp"

class HumanA {

private:
			std::string _name;
			Weapon &_weapon;

public:
			HumanA(std::string name, Weapon &weapon);
//			HumanA();
			~HumanA();
			void attack();

};

#endif
