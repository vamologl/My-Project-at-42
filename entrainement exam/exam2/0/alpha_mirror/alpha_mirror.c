#include <unistd.h>

int	ft_index(int c)
{
	int	ch;

	ch = c;
	if (c >= 'a' && c <= 'z')
		return (ch - 97);
	if (c >= 'A' && c <= 'Z')
		return (ch - 65);
	return (ch);
}

void	ft_alphamirror(char *str)
{
	char	almin[] = "zyxwvutsrqponmlkjihgfedcba";
	char	almaj[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	char 	stock;
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			j = ft_index(str[i]);
			stock = almin[j];
			write(1, &stock, 1);
			//write(1, "1", 1);
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			j = ft_index(str[i]);
			stock = almaj[j];
			write(1, &stock, 1);
			//write(1, "2", 1);
		}
		else if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
		{
			stock = str[i];
			write(1, &stock, 1);
			//write(1, "3", 1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_alphamirror(av[1]);
	write(1, "\n", 1);
	return (0);
}
