/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:57:02 by vamologl          #+#    #+#             */
/*   Updated: 2023/03/23 11:21:43 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	char	*string;

	string = (char *)malloc(sizeof(char) + 1);
	if (size == 0)
	{
		free(string);
		return ('\0');
	while (i < size)
	{
		string[i] = strs[i];
		i++;
	}
	return (string);
}

int	main(void)
{
	char	
	return (0);
}
