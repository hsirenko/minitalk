/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:35:35 by hsirenko          #+#    #+#             */
/*   Updated: 2023/04/10 05:06:45 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putchar_hex_lower(int nbr)
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

int	ft_putchar_hex_upper(int nbr)
{
	if (nbr <= 9)
	{
		nbr += 48;
		write(1, &nbr, 1);
	}
	if (nbr >= 10 && nbr <= 15)
	{
		nbr += 55;
		write(1, &nbr, 1);
	}
	return (1);
}

int	ft_putchar_hex_upper_lower(int nbr, int x)
{
	if (nbr >= 0 && nbr <= 9)
	{
		nbr += 48;
		write(1, &nbr, 1);
	}
	else if (nbr >= 10 && nbr <= 15 && x == 'X')
	{
		ft_putchar_hex_upper(nbr);
	}
	else if (nbr >= 10 && nbr <= 15 && x == 'x')
	{
		ft_putchar_hex_lower(nbr);
	}
	return (1);
}

int	ft_puthex_upper_lower(unsigned int nbr, int x)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_puthex_upper_lower(nbr / 16, x);
		i += ft_putchar_hex_upper_lower(nbr % 16, x);
	}
	if (nbr < 16)
	{
		i += ft_putchar_hex_upper_lower(nbr, x);
	}
	return (i);
}

// int	ft_puthex_lower(unsigned int nbr)
// {
// 	int	i;

// 	i = 0;
// 	if (nbr >= 16)
// 	{
// 		i += ft_puthex_lower(nbr / 16);
// 		i += ft_putchar_hex_lower(nbr % 16);
// 	}
// 	if (nbr < 16)
// 	{
// 		i += ft_putchar_hex_lower(nbr);
// 	}
// 	return (i);
// }

/*char	percent(char i)
{
	if (i == '%')
	{
		i++;
		ft_putchar('%');
	}
	return (i);
}*/

// int main(void)
// {

// 	int return_value;
//     int return_value_original;

// 	return_value = ft_puthex_upper_lower(" %x ", 12);
// 	printf("\n");
// 	return_value_original = printf(" %x ", 12);
// 	printf("\n");
// 	printf("My ft_printf returns: %i\n", return_value);
// 	printf("Original printf returns: %i\n", return_value_original);
// }

	/*char *b = "%%c";
	char i;

	i = percent(*b);
	printf("\n");

	printf("privet, ja %s, u menja %i", b, i);
	return (0);


	char b = 'd';
	
    int return_value_original = printf("%x\n", b);


    printf("Original printf returns: %i\n", return_value_original);
}*/