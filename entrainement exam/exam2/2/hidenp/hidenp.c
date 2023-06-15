#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	hidenp(char *key, char *s)
{
	int	i = 0;
	int	j = 0;
	int	check = 0;

	while (key[i] != '\0')
	{
		while (s[j] != '\0')
		{
			if (s[j] == key[i])
			{
				i++;
				check += 1;
			}
			else
				j++;
		}
		if (check == ft_strlen(key))
		{
			write(1, "1", 1);
			return ;
		}
		else
			i++;
	}
	write(1, "0", 1);
	return ;
}

int	main(int ac, char **av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
