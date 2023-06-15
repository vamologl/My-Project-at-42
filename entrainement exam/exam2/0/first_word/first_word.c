#include <stdio.h>
#include <unistd.h>

void	fstw(char *s)
{
	int	i = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	//printf("%d\n", i);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fstw(av[1]);
	write(1, "\n", 1);
	return (0);
}
