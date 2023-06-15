#include <stdio.h>
#include <stdlib.h>

void	fprime(char *s)
{
	int	nb;
	int	div = 2;

	nb = atoi(s);
	if (nb == 1)
		printf("1");
	if (nb <= 1)
		return ;
	while (div <= nb)
	{
		if (nb % div == 0)
		{
			printf("%d", div);
			if (nb == div)
				return ;
			printf("*");
			nb = nb / div;
			div = 1;
		}
		div++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		fprime(av[1]);
	printf("\n");
	return (0);
}
