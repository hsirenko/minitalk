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

unsigned char   reverse_bits(unsigned char octet)
{
    int i;
    unsigned char res;

    i = 8;
    res = 0;
    while (i--)
    {
        res = (res << 1) + (octet % 2);
        octet = octet >> 1;
    }
    return (res);
}

void    sighandler_usr(int signum)
{
    static unsigned char i = 0;
    static int bits;
    unsigned char result;

    if (signum == SIGUSR1)
    {
        i |= (0x01 << bits);
    }
    bits++;
    if (bits == 8)
    {
        result = reverse_bits(i);
        write(1, &result, 1);

        bits = 0;
        i = 0;
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    ft_printf("PID: %d\n", pid);

    while (1)
    {
        signal(SIGUSR1, sighandler_usr);
        signal(SIGUSR2, sighandler_usr);
        pause();
    }
    return (0);
}