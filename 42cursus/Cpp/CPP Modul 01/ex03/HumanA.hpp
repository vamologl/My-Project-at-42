#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	private:
		std::string	nameHuman;
		Weapon &weapon;

	public:
		HumanA(std::string name, Weapon &newWeapon);
		~HumanA();
		void	setWeapon(Weapon _weapon);
		void	attack();
};
