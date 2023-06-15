#include <unistd.h>

int	indx(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a');
	if (c >= 'A' && c <= 'Z')
		return (c - 'A');
	else
		return (c);
}

void	rotone(char *s)
{
	char	chl[] = "bcdefghijklmnopqrstuvwxyza";
	char	chu[] = "BCDEFGHIJKLMNOPQRSTUVWXYZA";
	int	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			write(1, &chl[indx(s[i])], 1);
			i++;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			write(1, &chu[indx(s[i])], 1);
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
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}
