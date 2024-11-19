#include <string>

#pragma once

class Zombie
{
	private:

	std::string zombiename;

	public:

	void	announce(void);
	Zombie(std::string name);
	~Zombie(void);
};

