#include <unistd.h>
#include <stdio.h>

void	epur_str(char *s)
{
	int	i = 0;
	int	j = 0;

	while (s[i] == ' ')
		i++;
	while (s[j] != '\0')
		j++;
	j--;
	while (i <= j)
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\0')
		{
			if (s[i + 1] != ' ' || s[i + 1] != '\t' || s[i + 1] != '\0')
			{
				i++;
				write(1, " ", 1);
			}
			else
				i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
