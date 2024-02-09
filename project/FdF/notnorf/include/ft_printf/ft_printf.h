/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:06:02 by vamologl          #+#    #+#             */
/*   Updated: 2023/05/05 14:10:34 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

void	ft_putstr(char *s);
void	ft_putchar(int c);
void	ft_put_hex(unsigned int n, const char format);
void	ft_put_ptr(uintptr_t n);
void	ft_putchar_fd(char c, int fd);

int		ft_printchar(int c);
int		formats(va_list args, const char format);
int		ft_printf(const char *str, ...);
int		ft_printstr(char *s);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		ft_hex_len(unsigned int n);
int		ft_print_hex(unsigned int n, const char format);
int		ft_ptr_len(uintptr_t n);
int		ft_print_ptr(unsigned long long ptr);
int		ft_nlen(unsigned int n);
int		ft_print_unsigned(unsigned int n);

char	*ft_uitoa(unsigned int n);
char	*ft_itoa(int n);

#endif
