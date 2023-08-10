/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:48:58 by hsirenko          #+#    #+#             */
/*   Updated: 2023/04/10 05:15:36 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	counter(int i)
{
	int	a;

	a = 0;
	if (i <= 0)
	{
		a = a + 1;
	}
	while (i != 0)
	{
		i = i / 10;
		a++;
	}
	return (a);
}

int	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr <= 9 && nbr >= 0)
	{
		ft_putchar (nbr + 48);
	}
	else if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(nbr * -1);
	}
	return (counter(nbr));
}

int	ft_unsigned_int(unsigned int nb)
{
	int	a;

	a = 0;
	if (nb > 9)
	{
		a += ft_putnbr(nb / 10);
		a += ft_putnbr(nb % 10);
	}
	else if (nb <= 9 && nb >= 0)
	{
		a += ft_putchar (nb + 48);
	}
	return (a);
}
