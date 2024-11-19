#include <string>
#include "Contact.hpp"

# pragma once

class Phonebook
{
	public:

	void	addContact(void);
	void	printContact(void);
	void	search(void);
	void	printValueIndex(int i);
	void	printTab(void);
	void	printTabCol(std::string str);

	private:

	int	index = 0;
	int len = 0;
	Contact	contact[8];	
};

