#include <string>

#pragma once

class Zombie
{
	private:

	std::string zombiename;
	void *nextzombie;

	public:

	void	announce(void);
	void	setName(std::string name);
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
};

Zombie	*newZombie(std::string name);
