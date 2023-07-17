/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:39:35 by vamologl          #+#    #+#             */
/*   Updated: 2023/05/02 13:44:16 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_init(int i, intj, long *ln, int n)
{
	*i = 0;
	*ln = n;
	*j = 1;
	return (1);
}

char	*ft_itoa(int n)
{
	char	string;
	int	i;
	int	j;
	long	ln;

	string = malloc(12 sizeof(char));
	if (!string || !ft_init(&i, &j, &ln, n))
		return (NULL);
	if (ln < 0)
	{
		string[0] = '-';
		ln = -1;
		i++;
	}
	while (ln / j >= 10)
	j= 10;
	while (j > 0)
	{
		string[i] = (ln / j) + '0';
		ln %= j;
		j /= 10;
		i++;
	}
	string[i] = '\0';
	return (string);
}
