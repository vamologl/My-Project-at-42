#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_print_str(char *s);
int	ft_print_char(char c);

/*---------------------------*/

int	hexa_len(unsigned int num)
{
	int	len = 0;

	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void	ft_put_hexa(unsigned int n)
{
	if (n >= 16)
	{
		ft_put_hexa(n / 16);
		ft_put_hexa(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_print_char(n + '0');
		else
			ft_print_char(n - 10 + 'a');
	}
}

int	ft_print_hexa(unsigned int num)
{
	if (0 == num)
	{
		write(1, "0", 1);
		return (0);
	}
	else
		ft_put_hexa(num);
	return (hexa_len(num));
}



/*---------------------------*/
unsigned int	ft_intlen(long n_l, int sign)
{
	unsigned int	len = 0;

	if (0 == n_l) //check if n_l is zero
		return (1);
	while (n_l > 0) //while it's not under zero
	{
		n_l /= 10; // it's just random text at this point
		len++;
	}
	if (sign == -1) // check if n_l is negatif with the flag
		len++;
	return (len);
}

static void	convert_to_nb(char *conv, long n_l, unsigned int nb_digit, int sign)
{
	conv[nb_digit] = '\0';
	nb_digit--;
	conv[nb_digit] = n_l % 10 + '0';
	n_l /= 10;
	while (n_l > 0)
	{
		conv[--nb_digit] = n_l % 10 + '0';
		n_l /= 10;
	}
	if (sign == -1)
		conv[0] = '-';
}

char	*ft_itoa(int n)
{
	char		*conv;
	long		n_l;
	unsigned int	nb_digit =  0;
	int		sign = 1;

	if (0 > n)
	{
		sign *= -1; 		// store Negatif
		n_l = (long)n * -1; 	// Put n into Positif
	}
	else
		n_l = n; //set nl as n
	nb_digit = ft_intlen(n_l, sign); // get the len
	conv = malloc(sizeof(char) * (nb_digit + 1));
	if (!(conv))
		return (NULL);
	convert_to_nb(conv, n_l, nb_digit, sign);
	return (conv);
}
/*----------------------------------------------------*/

int	ft_print_int(int n)
{
	int	len = 0;
	char	*num;

	num = ft_itoa(n);
	len = ft_print_str(num);
	free(num);
	return (len);
}

int	ft_print_str(char *s)
{
	int i = 0;
	
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return(i);
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/*--------------------------------------------*/

int	ft_format(va_list args, const char format)
{
	int	print_length = 0;

	if (format == 's') //s = char string
		print_length += ft_print_str(va_arg(args, char *));
	else if (format == 'd') // d == int
		print_length += ft_print_int(va_arg(args, int));
	else if (format == 'x') // x = Hexavalue
		print_length += ft_print_hexa(va_arg(args, unsigned int));
	return(print_length);
}

int	ft_printf(const char *str, ... )
{
	int	print_length = 0;
	int	i = 0;
	va_list	args;

	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_format(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

/*------------------------------------------------*/
/*
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_printf("arg 1 is %s\nint is = %d\n hexa is %x\n", av[1], atoi(av[2]), atoi(av[2]));
		printf("arg 1 is = %s\nint is = %d\n hexa is %x\n", av[1], atoi(av[2]), atoi(av[2]));

	}
}*/
