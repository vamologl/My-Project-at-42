#include <unistd.h>
#include <stdio.h>

int	indexr(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 1);
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 1);
	else 
		return (c);
}

void	repeat_alpha(char *s)
{
	int	i = 0;
	int	rep;

	while (s[i] != '\0')
	{
		rep = indexr(s[i]);
		//printf("%d\n", rep); //debug
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			while (rep != 0)
			{
				write(1, &s[i], 1);
				rep--;
			}
		else
			write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}
