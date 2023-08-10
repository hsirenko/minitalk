/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helensirenko <helensirenko@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:23:05 by helensirenko      #+#    #+#             */
/*   Updated: 2023/08/01 16:23:06 by helensirenko     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <sys/signal.h>
# include "../ft_printf/ft_printf.h"

unsigned char   reverse_bits(unsigned char octet);
void            sighandler_usr(int signum, siginfo_t *info, void *context);
void            send_signals(char *msg, int pid);
int	            ft_atoi(const char *str);

#endif