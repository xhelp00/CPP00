#ifndef WEAPON_CLASS_HPP
#define WEAPON_CLASS_HPP

# include <string>

class Weapon {

private:
			std::string _type;

public:
			//Weapon();
			Weapon(std::string type);
			Weapon();
			~Weapon();
			const std::string& getType();
			void setType(std::string str);

};

#endif
