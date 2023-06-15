#include <unistd.h>

void	ft_wnumb(int i)
{
	if (i > 9)
		ft_wnumb(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

int	main(void)
{
	int	number = 1;

	while (number <= 100)
	{
		if (number % 3 == 0 && number % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (number % 5 == 0)
			write(1, "buzz", 4);
		else if (number % 3 == 0)
			write(1, "fizz", 4);
		else
			ft_wnumb(number);
		write(1, "\n", 1);
		number++;
	}
}
