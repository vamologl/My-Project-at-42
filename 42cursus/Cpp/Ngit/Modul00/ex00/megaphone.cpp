/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:42:11 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/24 11:13:27 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string	PrintUpperString(std::string s)
{
	int	i = 0;

	while (s[i])
	{
		s[i] = toupper(s[i]);
		i++;
	}
	return (s);
}

int main(int c, char **v)
{
	int	i = 1;
	
	if (c < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (v[i])
		{
			std::cout << PrintUpperString(v[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}