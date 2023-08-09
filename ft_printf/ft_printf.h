/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:48:41 by hsirenko          #+#    #+#             */
/*   Updated: 2023/04/10 05:52:26 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		counter(int i);
int		ft_putnbr(int nbr);
int		ft_unsigned_int(unsigned int nb);
int		ft_putchar_hex_lower(int nbr);
int		ft_putchar_hex_upper(int nbr);
int		ft_puthex_upper_lower(unsigned int nbr, int x);
int		ft_ptr_hex_lower(unsigned long long nbr);
int		ft_ptr_lower(unsigned long long nbr);
int		formatter(va_list args, const char *str);
int		formatter1(va_list args, const char *str);
int		ft_printf(const char *s, ...);
int		ptr_hex(unsigned long long nbr);

#endif