#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->nameHuman << " attacks with their " << 
	this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &newWeapon): nameHuman(name), weapon(newWeapon)
{
	std::cout << "created HummanA : " << this->nameHuman << " with weapon " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Destroyed HummanA : " << this->nameHuman << std::endl;
}

void	HumanA::setWeapon(Weapon _weapon)
{
	this->weapon = _weapon;
}
