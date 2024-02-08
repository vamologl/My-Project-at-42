#include "../include/minishell.h"

int	check_quote(const char *s, int i, char c)
{
	int	len;

	len = 0;
	i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len + 1);
}

int	ft_special_lword(char const *s, int i)
{
	int	size;

	size = 0;
	if (s[i] == '\"' && s[i])
		size = check_quote(s, i, '\"');
	else if (s[i] == '\'' && s[i])
		size = check_quote(s, i, '\'');
	else
	{
		size = check_quote(s, i, ' ');
	}
	return (size + 1);
}

char	**ft_special_split(char const *s)
{
	int		i;
	int		j;
	int		size;
	int		word;
	char	**strs;

	i = 0;
	j = -1;
	word = countwords(s, 0, 0, 0);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == ' ')
			i++;
		size = ft_special_lword(s, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
			return (NULL);
		i += size;
	}
	strs[j] = 0;
	return (strs);
}

int	ft_strlen_wo_quote(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			i++;
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

char	*ft_strstrip(char *s)
{
	char	*ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	ret = malloc(sizeof(char *) * ft_strlen_wo_quote(s) + 1);
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			i++;
		else
		{
			if (s[i + 1] == '\0' && s[i] == ' ')
			{
				i++;
				j++;
				break;
			}
			ret[j] = s[i];
			i++;
			j++;
		}
	}
	ret[j] = '\0';
	//printf("|%s|\n", ret);
	return (ret);
}
