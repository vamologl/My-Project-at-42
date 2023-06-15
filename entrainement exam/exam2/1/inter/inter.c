#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i = 0;

	while(s[i] != '\0')
		i++;
	return (i);
}

void	inter(char *key, char *str)
{
	int	i = 0;
	int	k = 0;
	int	l = 0;

/*	//debug
	int	a = 0;
	int	b = 0;
	int	c = 0;

	//debug
	printf("%s %d %s \n", "if est passe", a, "fois");
	printf("%s %d %s \n", "else if est passe", b, "fois");
	printf("%s %d %s \n", "else est passe", c, "fois");*/

	while (key[i] != '\0')
	{
		k = 0;
		while (str[k] != '\0')
		{
			if (key[i] == str[k])
			{
				l = 0;
				while (key[l] != key[i])
					l++;
				if (l == i)
				{
					l = 0;
					while (str[l] != str[k])
						l++;
					if (l == k)
						write(1, &key[i], 1);
				}
			}
			k++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
