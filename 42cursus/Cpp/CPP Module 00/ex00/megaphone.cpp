/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:42:11 by vamologl          #+#    #+#             */
/*   Updated: 2024/10/24 11:31:07 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string	PrintUpperString(std::string s)
{
	for (int i = 0; s[i]; i++)
		s[i] = toupper(s[i]);
	return (s);
}

int main(int c, char **v)
{
	int	i = 0;
	
	if (c < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (v[++i])
			std::cout << PrintUpperString(v[i]);
		std::cout << std::endl;
	}
	return (0);
}