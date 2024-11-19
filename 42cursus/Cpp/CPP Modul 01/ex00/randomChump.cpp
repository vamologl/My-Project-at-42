#include "Zombie.hpp"

void	RandomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}