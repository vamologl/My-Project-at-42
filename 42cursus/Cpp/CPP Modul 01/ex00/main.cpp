#include "Zombie.hpp"

void	RandomChump(std::string name);
Zombie* newZombie(std::string name);

int	main(void)
{
	Zombie	z = Zombie("Michel");
	z.announce();
	RandomChump("Greg");
	return (0);
}