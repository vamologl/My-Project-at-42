#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
	private:
		std::string	nameHuman;
		Weapon *weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon &_weapon);
		void	attack();
};
