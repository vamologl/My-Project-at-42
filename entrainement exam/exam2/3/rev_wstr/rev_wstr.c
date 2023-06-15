#include <unistd.h>
//#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	rev_wstr(char *s)
{
	char	*tmp = s;
	char	*rev = NULL;
	int	len = ft_strlen(s);
	len--;

	//printf("%d\n", ft_strlen(s));
	while (tmp[len] != '\0')
	{
		//printf("%s\n", "loop");
		if (tmp[len - 1] == ' ')
		{
			//printf("%s\n", "if");
			rev = &tmp[len];
			while (*rev && *rev != ' ')
			{
				ft_putchar(*rev);
				rev++;
				//printf("%s\n", "if while");
			}
			ft_putchar(' ');
		}
		else if (len == 0)
		{
			//printf("%s\n", "else if");
			rev = &tmp[len];
			while (*rev && *rev != ' ')
			{
				ft_putchar(*rev);
				rev++;
				//printf("%s\n", "else if while");
			}
		}
		len--;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
