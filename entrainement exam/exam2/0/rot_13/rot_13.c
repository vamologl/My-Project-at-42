#include <unistd.h>

int	indx(int c)
{
	if (c >= 'a' && c<= 'z')
		c = c - 'a';
	if (c >= 'A' && c<= 'Z')
		c = c - 'A';
	return (c);
}

void	rot_13(char *s)
{
	int	i = 0;
	int	j;
	char	chmin[] = "nopqrstuvwxyzabcdefghijklm";
	char	chmax[] = "NOPQRSTUVWXYZABCDEFGHIJKLM";

	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			j = indx(s[i]);
			write(1, &chmin[j], 1);
			i++;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			j = indx(s[i]);
			write(1, &chmax[j], 1);
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
		rot_13(av[1]);
	write(1, "\n", 1);
	return (0);
}
