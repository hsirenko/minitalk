/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helensirenko <helensirenko@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:45:49 by helensirenko      #+#    #+#             */
/*   Updated: 2023/08/09 17:31:56 by helensirenko     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/signal.h>
#include "minitalk.h"

int	ft_atoi(const char *str)
{
    int	result;
    int	sign;
    int	i;

    i = 0;
    result = 0;
    sign = 1;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * sign);
}

void send_signals(char *msg, int pid)
{
    int i;
    int bitshift;

    i = 0;
    bitshift = -1;
    while (msg[i] != '\0')
    {
        while (++bitshift < 8)
        {
            if (msg[i] & (0x80 >> bitshift))
            {
                kill(pid, SIGUSR1);
                usleep(500);
            }
            else
            {
                kill(pid, SIGUSR2);
                usleep(500);
            }
            usleep(300);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    if (argc != 3)
    {
        printf("Error: Too few argc\n");
        exit(EXIT_FAILURE);
    }
    pid = ft_atoi(argv[1]);
    while (argv[2][i] != '\0')
    {
        send_signals(&argv[2][i], pid);
        i++;
    }
    sleep(1);
    return (0);
}