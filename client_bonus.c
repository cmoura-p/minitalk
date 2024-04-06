/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:30:27 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/04/06 21:27:44 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void    send_char_bonus(int pid, unsigned char let)
{
    int i;
    int bit;
      
    i = 0;
    while ( i < 8)
    {
        bit = (let >> i) & 1;
        if (bit == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(500);
        i++;
    }
}

static void signal_handler(int sig)
{
    if (sig == SIGUSR1)
        write(1, "\nWell Done!\n\n", 13);
    exit(0);
}

int main(int ac, char **av)
{
    int             i;
    static int      pid;
    unsigned char   *str;

    signal(SIGUSR1, signal_handler);
    if (ac == 3)
    {
        pid = ft_atoi(av[1]);
        str = (unsigned char *)av[2];
        i = 0;
        while (str[i])
        {
            send_char_bonus(pid, str[i]);
            i++;
        }
        send_char_bonus(pid, str[i]);
    }
    else
    {
        write(1, "You must type the pid and the message\n", 39);
        write(1, "./client_bonus [PID] [MESSAGE]\n", 31);
    }
    return (0);
}
