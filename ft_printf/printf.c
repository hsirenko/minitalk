/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:36:04 by hsirenko          #+#    #+#             */
/*   Updated: 2023/04/10 18:34:21 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	formatter(va_list args, const char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (*str == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (*str == 's')
	{
		s = va_arg(args, char *);
		i += ft_putstr(s);
	}
	else if (*str == 'd' || *str == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (*str == 'x' || *str == 'X')
		i += ft_puthex_upper_lower(va_arg(args, int), *str);
	else if (*str == 'u')
		i += ft_unsigned_int(va_arg(args, unsigned int));
	else if (*str == 'p')
		i += ptr_hex(va_arg(args, unsigned long long));
	else if (*str == '%')
	{
		i++;
		i = ft_putchar('%');
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			c;
	va_list		args;

	va_start (args, s);
	i = 0;
	c = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			c += formatter(args, &s[i]);
		}
		else if (s[i] != '%')
			c += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (c);
}
