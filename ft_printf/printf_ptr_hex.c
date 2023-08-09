/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:36:24 by hsirenko          #+#    #+#             */
/*   Updated: 2023/04/10 05:52:14 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_hex_lower(unsigned long long nbr)
{
	if (nbr <= 9)
	{
		nbr += 48;
		write(1, &nbr, 1);
	}
	if (nbr >= 10 && nbr <= 15)
	{
		nbr += 87;
		write(1, &nbr, 1);
	}
	return (1);
}

int	ft_ptr_lower(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_ptr_lower(nbr / 16);
		i += ft_ptr_hex_lower(nbr % 16);
	}
	if (nbr < 16)
	{
		i += ft_ptr_hex_lower(nbr);
	}
	return (i);
}

int	ptr_hex(unsigned long long nbr)
{
	int		i;

	i = 0;
	if (nbr == (unsigned long long) NULL || nbr == 0)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	i += ft_putstr("0x");
	if (nbr >= 16)
	{
		i += ft_ptr_lower(nbr / 16);
		i += ft_ptr_hex_lower(nbr % 16);
	}
	else if (nbr < 16)
	{
		i += ft_ptr_hex_lower(nbr);
	}
	return (i);
}
