#include <string>
#include "Contact.hpp"

# pragma once

class PhoneBook
{
	public:

	void	addContact(void);
	void	search(void);
	void	fill(void);
	PhoneBook(void);
	~PhoneBook(void);

	private:

	void	printContact(void);
	void	printTab(void);
	void	printTabCol(std::string str);
	void	printValueIndex(int i);
	int	index;
	int len;
	Contact	contact[8];	
};

