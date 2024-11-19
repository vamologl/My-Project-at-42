/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:15:25 by vamologl          #+#    #+#             */
/*   Updated: 2024/10/28 11:36:01 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

void	Contact::setFirstName(std::string str)
{
	firstn = str;
}
void	Contact::setLastName(std::string str)
{
	lastn = str;
}

void	Contact::setNickname(std::string str)
{
	nick = str;
}
void	Contact::setPhone(std::string str)
{
	phone = str;
}

void	Contact::setSecret(std::string str)
{
	secret = str;
}

std::string	Contact::returnFirst(void) const
{
	return (this->firstn);
}

std::string	Contact::returnLast(void) const
{
	return (this->lastn);
}

std::string	Contact::returnNick(void) const
{
	return (this->nick);
}

std::string	Contact::returnPhone(void) const
{
	return (this->phone);
}

std::string	Contact::returnSecret(void) const
{
	return (this->secret);
}

int	onlySpacesOrTabs(std::string str)
{
	for (int i = 0; str[i] && str[i] != '\0'; i++)
	{
		if (str[i] != ' ' || str[i] != '\t')
			return (0);
	}
	return (1);
}

int ft_strlen(std::string str)
{
	int i = 0;
	
	while(str[i])
		i++;
	return (i);
}

int	Contact::verifCharInput(int loop)
{
	std::string string;

	getline(std::cin, string);
	if (onlySpacesOrTabs(string) == 1)
		return (0);
	if (loop == 3)
	{
		for (int i = 0; string[i]; i++)
		{
			if (string[i] > '9' || string[i] < '0')
				return (0);
		}
		if (ft_strlen(string) != 10)
			return (0);
	}
	if (onlySpacesOrTabs(string) == 1)
		return (0);
	if (loop == 0)
		setFirstName(string);
	else if (loop == 1)
		setLastName(string);
	else if (loop == 2)
		setNickname(string);
	else if (loop == 3)
		setPhone(string);
	else if (loop == 4)
		setSecret(string);	
	return (1);
}

void	Contact::setValue(void)
{
	std::string string;
	int loop = 0;;

	while (!std::cin.eof() && loop < 5)
	{
		if (loop == 0)
			std::cout << "First name : ";
		else if (loop == 1)
			std::cout << "Last name : ";
		else if (loop == 2)
			std::cout << "Nickname : ";
		else if (loop == 3)
			std::cout << "Phone : ";
		else if (loop == 4)
			std::cout << "Darkest Secret : ";
		if (verifCharInput(loop) != 1)
			std::cout << std::endl << "Error, incorrect input, please retry" << std::endl;
		else
			loop++;
	}
}
