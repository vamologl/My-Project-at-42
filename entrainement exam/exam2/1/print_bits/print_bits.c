#include <unistd.h>
#include <stdio.h>

int	get_int(unsigned char s)

{
	int	i = s;
	return (i);
}

void	print_bits(unsigned char octet)
{
	int	i = 0;
	int	nb = get_int(octet);

	while (i <= 7)
	{
		if (i == 0 && nb - 128 >= 0)
		{
			nb = nb - 128;
			write(1, "1", 1);
			i++;
		}
		else if (i == 1 && nb - 64 >= 0)
		{
			nb = nb - 64;
			write(1, "1", 1);
			i++;
		}
		else if (i == 2 && nb - 32 >= 0)
		{
			nb = nb - 32;
			write(1, "1", 1);
			i++;
		}
		else if (i == 3 && nb - 16 >= 0)
		{
			nb = nb - 16;
			write(1, "1", 1);
			i++;
		}
		else if (i == 4 && nb - 8 >= 0)
		{
			nb = nb - 8;
			write(1, "1", 1);
			i++;
		}
		else if (i == 5 && nb - 4 >= 0)
		{
			nb = nb - 4;
			write(1, "1", 1);
			i++;
		}
		else if (i == 6 && nb - 2 >= 0)
		{
			nb = nb - 2;
			write(1, "1", 1);
			i++;
		}
		else if (i == 7 && nb - 1 >= 0)
		{
			nb = nb - 1;
			write(1, "1", 1);
			i++;
		}
		else
		{
			write(1, "0", 1);
			i++;
		}
	}
}

/*
int	main(void)
{
	char	c = 254;
	printf("%d\n", get_int(c));
	print_bits(c);
	return (0);
}*/
