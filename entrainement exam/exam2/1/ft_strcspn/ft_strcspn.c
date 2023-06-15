#include <string.h>
//#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i = 0;
	size_t	j = 0;
	{
		while (s[i] != '\0')
		{
			if (s[i] == reject[j])
				break ;
			else if (reject[j] == '\0')
			{
				i++;
				j = 0;
			}
			else
				j++;
		}
	}
	return (i);
}
/*
int	main(void)
{
	char	s[] = "abcdefghijklmnopqrstuvwxyz";
	char	reject[] = "agiz";

	printf("%ld\n", ft_strcspn(s, reject));
	printf("%ld\n", strcspn(s, reject));
	return(0);
}*/
