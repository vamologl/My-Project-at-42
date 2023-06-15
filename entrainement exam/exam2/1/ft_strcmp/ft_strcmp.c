/*#include <string.h>
#include <stdio.h>*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char	s[] = "abcdef2";
	char	s1[] = "abcdef1";

	printf("%d\n", ft_strcmp(s, s1));
	printf("%d\n", strcmp(s, s1));
	return (0);
}*/
