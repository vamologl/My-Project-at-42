/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:13:11 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/26 14:06:55 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "Phonebook.hpp"

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
	std::cout << "EXIT : leave the Phonebook" << std::endl << std::endl;
}

int main(void)
{
	Phonebook phonebook;
	std::string	str;
	
	while (!std::cin.eof())
	{
		commandsDisplay();
		getline(std::cin, str);
		str = SetToUpper(str);
		if (str == "ADD")
		{
			std::cout << "\033[2J\033[1;1H";
			phonebook.addContact();
			std::cout << "\033[2J\033[1;1H";
		}
		else if (str == "SEARCH")
		{
			std::cout << "\033[2J\033[1;1H";
			phonebook.search();
		}
		else if (str == "EXIT")
			break ;
		else 
			std::cout << "\033[2J\033[1;1H";
	}
	return (0);
}

/*----------------------------
*
*  1|1234567890|0123456789|0123456789|
*  2|    michel|  lastname|  Nickname|
*  3|      Greg|    Existe|         G|
*  4|Randomnam.|RandomLas.|Nicknamea.|
*  5| FirstName|  LastName|  Nickname|
*
----------------------------*/