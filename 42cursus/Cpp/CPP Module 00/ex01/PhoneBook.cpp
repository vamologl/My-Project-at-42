#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

/*-Utils-*/

int	ft_strcmp(std::string s0, std::string s1)
{
	int i = 0;

	while (s0[i] && s1[i])
	{
		if (s0[i] == s1[i])
			i++;
		else if (s0[i] != s1[i])
			return (s0[i] - s1[i]);
		else
			return (-1);
	}
	return (0);
}

int	check_string(std::string s)
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] > '9' || s[i] < '0')
			return (1);
	}
	return (0);
}

/*------------------------------------*/
/*-Print-*/

void	PhoneBook::printContact(void)
{
	for(int i = 0; i <= len; i++)
		printValueIndex(i);
}

void	PhoneBook::printValueIndex(int i)
{
	std::cout << "First name : " <<  contact[i].returnFirst() << std::endl;
	std::cout << "Last name : " << contact[i].returnLast() << std::endl;
	std::cout << "Nickname : " << contact[i].returnNick() << std::endl;
	std::cout << "Phone : " << contact[i].returnPhone() << std::endl;
	std::cout << "Darkest secret : " << contact[i].returnSecret() << std::endl;
}

void	PhoneBook::printTabCol(std::string str)
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

void	PhoneBook::printTab(void)
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
	std::cout << "---------------------------------------" << std::endl << std::endl;
}

/*------------------------------------*/
/*-PhoneBook-*/

void	PhoneBook::search(void)
{
	std::string str;
	int	userindex;

	printTab();
	std::cout << "Wich contact do you want ? : ";
	getline(std::cin, str);
	if (ft_strcmp(str, "\n") == 0 || check_string(str) == 1)
	{
		std::cout << "Error, Input value is not an index available" << std::endl << std::endl;
		return ;
	}
	std::istringstream iss(str);
	iss >> userindex;

	if (userindex > len || userindex == 0)
		std::cout << "No values found in index " << userindex << std::endl << std::endl;
	else
	{
		std::cout << "Contact " << userindex << " : " << std::endl;
		printValueIndex(userindex - 1);
		std::cout << std::endl;
	}
}

void	PhoneBook::addContact(void)
{
	if (index == 8)
		index = 0;
	if (len < 8)
		len++;
	contact[index].setValue();
	index++;
}

void	PhoneBook::fill(void)
{
	for (int i = index; i < 8; i++)
	{
		contact[i].setFirstName("Michel");
		contact[i].setLastName("Longstring");
		contact[i].setNickname("Mi");
		contact[i].setPhone("0612345678");
		contact[i].setSecret("This is a secret");
	}
	len = 8;
}

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->len = 0;
}

PhoneBook::~PhoneBook(void)
{
}