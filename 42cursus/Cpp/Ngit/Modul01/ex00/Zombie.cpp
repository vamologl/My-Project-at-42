#include "Zombie.hpp"
#include <iostream>

void	Zombie::SetNameZombie(std::string name)
{
	zombiename = name;
}

void	Zombie::announce(void)
{
	std::cout << zombiename << ": BraiiiiiiinnnzzzZ..." << std::endl;
}