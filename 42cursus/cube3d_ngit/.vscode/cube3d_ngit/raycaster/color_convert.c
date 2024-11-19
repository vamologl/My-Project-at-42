/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:49:11 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/05 14:51:34 by vamologl         ###   ########.fr       */
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

int	char_convert(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (ch - '0');
	else if (ch >= 'A' && ch <= 'F')
		return (10 + (ch - 'A'));
	else if (ch >= 'a' && ch <= 'f')
		return (10 + (ch - 'a'));
	else
		return (-1);
}

int	htoi(const char *s)
{
	int	hexval;
	int	value;
	int	i;

	value = 0;
	i = 0;
	if (s == NULL || strlen(s) != 6)
	{
		printf("Invalid hex color format = %s\n", s);
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

static int	ft_get_len(int value, int base, int *sign)
{
	int	len;
	int	temp_value;

	len = 1;
	*sign = 0;
	if (value < 0 && base == 10)
	{
		*sign = 1;
		value = -value;
	}
	temp_value = value;
	temp_value /= base;
	while (temp_value != 0)
	{
		temp_value /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	char	*result;
	char	*base_chars;
	int		len;
	int		sign;

	base_chars = "0123456789abcdef";
	len = ft_get_len(value, base, &sign);
	result = (char *)gc_alloc(sizeof(char) * len + sign + 1, 2);
	if (!result)
		return (NULL);
	result[len + sign] = '\0';
	if (sign)
		value = -value;
	while (len--)
	{
		result[len + sign] = base_chars[value % base];
		value /= base;
	}
	if (sign)
		result[0] = '-';
	if (ft_strlen(result) < 2)
		result = ft_strjoin_gc("0", result, 2);
	return (result);
}
