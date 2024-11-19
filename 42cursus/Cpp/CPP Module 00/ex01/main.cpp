/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:13:11 by vamologl          #+#    #+#             */
/*   Updated: 2024/10/24 14:11:44 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

std::string	SetToUpper(std::string str)
{
	for(int i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
	return (str);
}

void	commandsDisplay(void)
{
	std::cout << "-- Commands avilable --" << std::endl;
	std::cout << "ADD : add a contact" << std::endl;
	std::cout << "SEARCH : search in all saved contact" << std::endl;
	std::cout << "FILL : fill empty contact" << std::endl;
	std::cout << "EXIT : leave the PhoneBook" << std::endl << std::endl;
}

int main(void)
{
	PhoneBook PhoneBook;
	std::string	str;
	
	while (!std::cin.eof())
	{
		commandsDisplay();
		getline(std::cin, str);
		str = SetToUpper(str);
		if (str == "ADD")
		{
			std::cout << "\033[2J\033[1;1H";
			PhoneBook.addContact();
			std::cout << "\033[2J\033[1;1H";
		}
		else if (str == "SEARCH")
		{
			std::cout << "\033[2J\033[1;1H";
			PhoneBook.search();
		}
		else if (str == "FILL")
		{
			PhoneBook.fill();
			std::cout << "\033[2J\033[1;1H";
		}
		else if (str == "EXIT")
			break ;
		else 
			std::cout << "\033[2J\033[1;1H";
	}
	return (0);
}
