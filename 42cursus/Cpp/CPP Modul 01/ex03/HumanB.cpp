#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout << this->nameHuman << " attacks with their " << 
	this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name): nameHuman(name), weapon(NULL)
{
	std::cout << "created HummanB : " << this->nameHuman << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Destroyed HummanB : " << this->nameHuman << std::endl;
}

void	HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}