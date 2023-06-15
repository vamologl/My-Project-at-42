#include <unistd.h>

void	ft_replace(char *str, char c, char r)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			write(1, &r, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 4)
		if (!(av[3][1] != '\0' || av[2][1] != '\0'))
			ft_replace(av[1], av[2][0], av[3][0]);
	write(1, "\n", 1);
	return (0);
}
