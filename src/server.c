/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helensirenko <helensirenko@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:05:06 by helensirenko      #+#    #+#             */
/*   Updated: 2023/08/09 13:05:07 by helensirenko     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i--)
	{
		res = (res << 1) + (octet % 2);
		octet = octet >> 1;
	}
	return (res);
}

void	sighandler_usr(int signum, siginfo_t *info, void *context)
{
	static unsigned char	i = 0;
	static int				bits;
	unsigned char			result;

	(void)context;
	if (signum == SIGUSR1)
	{
		i |= (0x01 << bits);
	}
	bits++;
	if (bits == 8)
	{
		if (i == 0)
			kill(info->si_pid, SIGUSR2);
		result = reverse_bits(i);
		write(1, &result, 1);
		bits = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	act.sa_sigaction = sighandler_usr;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
