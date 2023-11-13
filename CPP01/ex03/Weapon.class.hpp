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
			std::string getType() const;
			void setType(std::string str);

};

#endif
