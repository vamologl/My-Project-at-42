#include <unistd.h>

void	ft_putnbr(int c)
{
	char	r;
	if (c >= 10)
		ft_putnbr(c / 10);
	r = (c % 10) + '0';
	write(1, &r, 1);
}

int	ft_atoi(char *s)
{
	int	i = 0;

	while (*s >= '0' && *s <= '9')
	{
	i *= 10;
	i += *s - '0';
	++s;
	}
	return (i);
}

int	is_prime(int n)
{
	int	i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_add_prime_sum(char *s)
{
	int	sum = 0;
	int	n;
	int	i = 2;

	n = ft_atoi(s);
	if (n < 0)
	{
		ft_putnbr(0);
		return ;
	}
	while (i <=  n)
	{
		if (is_prime(i) == 1)
			sum += i;
		++i;
	}
	ft_putnbr(sum);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_add_prime_sum(av[1]);
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
