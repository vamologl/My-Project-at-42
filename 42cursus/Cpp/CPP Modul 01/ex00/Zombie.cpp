#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce(void)
{
	std::cout << this->zombiename << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie object " << this->zombiename << " Destroyed" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->zombiename = name;
	std::cout << "Zombie object " << this->zombiename << " created" << std::endl;
}
