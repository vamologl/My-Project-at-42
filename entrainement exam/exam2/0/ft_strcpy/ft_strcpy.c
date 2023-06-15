#include <string.h>
#include <stdio.h>



char	*ft_strcpy(char *s1, char *s2)
{
	int	i = 0;
	char	*c;

	c = s1;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (c);
}

/*
int	main(void)
{
	char	src[] = "abcdefghijklmnopqrstuvwxyz";
	char	dest[] = "feqfeqqd";
	char	altdest[] = "feqfeqqd";

	printf("%s\n", ft_strcpy(dest, src));
	printf("%s\n", strcpy(altdest, src));
}*/
