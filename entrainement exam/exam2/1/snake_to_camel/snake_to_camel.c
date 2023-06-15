#include <unistd.h>

void	snktc(char *s)
{
	int	i = 0;

	while(s[i])
	{
		if (s[i] == '_')
		{
			i++;
			s[i] = s[i] - 32;
			write(1, &s[i], 1);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		snktc(av[1]);
	write(1, "\n", 1);
	return (0);
}
