/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:08:40 by vamologl          #+#    #+#             */
/*   Updated: 2024/06/27 14:01:15 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int char_convert(char ch)
{
	if (ch >= '0' && ch <= '9') 
		return (ch - '0');
	else if (ch >= 'A' && ch <= 'F') 
		return (10) + (ch - 'A');
	else if (ch >= 'a' && ch <= 'f') 
		return (10) + (ch - 'a');
	else 
		return (-1);
}

int htoi(const char *s)
{
	int hexval;
	int value = 0;
	int i = 0;
	
	if (s == NULL || strlen(s) != 6)
	{
		printf("Invalid hex color format\n");
		return (-1);
	}
	while (i < 6)
	{
		hexval = char_convert(s[i]);
		if (hexval == -1)
		{
			printf("Invalid hex character: %c\n", s[i]);
			return (-1);
		}
		value = value * 16 + hexval;
		i++;
	}
	return (value);
}

size_t	ft_strclen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}


char    *ft_itoa_base(int value, int base)
{
    char *base_chars = "0123456789abcdef";
    char *result;
    int temp_value = value;
    int len = 1;
    int sign = 0;

    if (value < 0 && base == 10)
    {
        sign = 1;
        value = -value;
    }
    while (temp_value /= base)
        len++;
    len += sign;
    result = (char *)gc_alloc(len + 1, 1);
    if (!result)
        return (NULL);

    result[len] = '\0';
    while (len--)
    {
        result[len] = base_chars[value % base];
        value /= base;
    }
    if (sign)
	{
        result[0] = '-';
	}
	if (ft_strcmp(result, "0") == 0)
		result = "00";
    return (result);
}

int get_color(char *s)
{
	int	i;
	int	j;
	int	count;
	char	*tmp;
	char	*ret;

	j = 0;
	i = 0;
	count = 0;
	ret = gc_alloc(sizeof(char *)* 1, 1); // need gc_alloc
	ret[0] = '\0';
	while (s[i] && i < ((int)ft_strlen(s)) && count < 3)
	{
		i = j;
		while (s[i] && ft_isdigit(s[i]) != 1)
			i++;
		j = i;
		while (s[i] && ft_isdigit(s[j]) == 1)
			j++;
		tmp = ft_itoa_base(ft_atoi(ft_sstrndup(s, j - i, i, 1)), 16);

		ret = ft_strjoin_gc(ret, tmp, 1);
		count++;
	}
	return (htoi(ret));
}
