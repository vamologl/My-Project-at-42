#include <unistd.h>

void	ft_checkcase(int c)
{
	int	ch;

	if (c >= 'a' && c <= 'z')
	{
		ch = c - 32;
		write(1, &ch, 1);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		ch = c + 32;
		write(1, &ch, 1);
	}
	else
		write(1, &c, 1);
}

void	ft_ulstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_checkcase(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_ulstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
