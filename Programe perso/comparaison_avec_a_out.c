#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", ft_strcmp(av[1], av[2]));
	else
		write(1, "empty", 5);
	write(1, "\n", 1);
	write(1, "0 = ok, autre = ko", 18);
	return (0);
}
