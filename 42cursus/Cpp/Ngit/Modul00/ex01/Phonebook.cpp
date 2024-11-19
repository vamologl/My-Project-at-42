#include "Phonebook.hpp"
#include <iostream>
#include <sstream>

void	Phonebook::printValueIndex(int i)
{
	std::cout << "First name : " <<  contact[i].returnFirst() << std::endl;
	std::cout << "Last name : " << contact[i].returnLast() << std::endl;
	std::cout << "Nickname : " << contact[i].returnNick() << std::endl;
	std::cout << "Phone : " << contact[i].returnPhone() << std::endl;
	std::cout << "Secret : " << contact[i].returnSecret() << std::endl;
}

void	Phonebook::printTabCol(std::string str)
{
	int	i = 0;
	while (str[i])
		i++;
	if (i >= 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		i--;
		while (++i < 10)
			std::cout << " ";
		std::cout << str;
	}
}

void	Phonebook::printTab(void)
{
	std::string str;
	
	std::cout << "Index" << "|" << "First name" << "|";
	std::cout << " Last Name" << "|" << "  Nickname" << "|" << std::endl;
	for (int i = 0; i < len; i++)
	{
		std::cout << "    " << i + 1<< "|";
		printTabCol(contact[i].returnFirst()) ;
		std::cout << "|";
		printTabCol(contact[i].returnLast());
		std::cout << "|";
		printTabCol(str = contact[i].returnNick());
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "----------------" << std::endl << std::endl;
}


void	Phonebook::search(void)
{
	std::string str;
	printTab();
	std::cout << "wich contact do you want ? : ";
	getline(std::cin, str);
	std::istringstream iss(str);
	int	userindex;
	iss >> userindex;
	if (userindex > len || userindex == 0)
		std::cout << "No values found in index " << userindex << std::endl << std::endl;
	else
	{
		std::cout << "contact " << userindex << " : " << std::endl;
		printValueIndex(userindex - 1);
		std::cout << std::endl;
	}
}


void	Phonebook::printContact(void)
{
	for(int i = 0; i <= len; i++)
		printValueIndex(i);
}

void	Phonebook::addContact(void)
{
	if (index == 8)
		index = 0;
	if (len < 8)
		len++;
	contact[index].setValue();
	index++;
}
