#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	int		n = 5;
	Zombie	*z = zombieHorde(n, "Greg");
	void	*ptr;

	for(int i = 0; i < n; i++)
	{
		ptr = &z[i];
		std::cout << "Zombie[" << i << "]|" << ptr << "| = ";
		z[i].announce();
	}
	delete [] z;
	return (0);
}