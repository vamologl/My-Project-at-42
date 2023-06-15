#include <unistd.h>
#include <stdio.h>

void	printnbr(int n)
{
	char	c;
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	else if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		printnbr(n / 10);
		printnbr(n % 10);
	}
}

int	main(int ac, char **av)
{
	(void)av;
	printnbr(ac - 1);
	write(1, "\n", 1);
	return (0);
}
