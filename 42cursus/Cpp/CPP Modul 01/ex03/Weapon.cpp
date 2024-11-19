#include "Weapon.hpp"

const std::string	&Weapon::getType()
{
	return(this->weapon_type);
}

Weapon::Weapon()
{
	this->weapon_type = "(null)";
}

Weapon::Weapon(std::string type)
{
	this->weapon_type = type;
}

void	Weapon::setType(std::string name)
{
	this->weapon_type = name;
}

Weapon::~Weapon()
{
}