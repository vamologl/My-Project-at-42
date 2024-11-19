#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce(void)
{
	std::cout << this->zombiename << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


void Zombie::setName(std::string name)
{
	this->zombiename = name;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie object " << this->zombiename << " Destroyed" << std::endl;
}

Zombie::Zombie(void)
{
	this->zombiename = "(null)";
	std::cout << "Zombie object " << this->zombiename << " created" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->zombiename = name;
	std::cout << "Zombie object " << this->zombiename << " created" << std::endl;
}