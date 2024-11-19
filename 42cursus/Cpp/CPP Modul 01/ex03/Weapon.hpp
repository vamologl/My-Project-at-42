#include <string>

#pragma once

class Weapon
{
	private:
		std::string weapon_type;

	public:
		void	setType(std::string type);
		const	std::string	&getType();
		Weapon(std::string type);
		Weapon();
		~Weapon();
};
