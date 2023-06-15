#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(ft_strlen(src) + 1));
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
int	main(void)
{
	char	s[] = "01234567890";

	printf("%s\n", ft_strdup(s));
	printf("%s\n", strdup(s));

	return (0);
}*/
