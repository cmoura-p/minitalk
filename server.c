/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:55:08 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/03/20 20:30:54 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minitalk.h"

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void    siga_handler(int signal, siginfo_t *info, void *ucontext)
{
    static int  i = 0;
    static char c = 0;

    if (signal == SIGUSR1)
        c |= (1 << i);
    i++;
    if (i == 8)
    {
        if (c == 0)
        {
            write(1, "\n", 1);
            kill(info->si_pid, SIGUSR1);
        }
        else
            write(1, &c, 1);
        i = 0;
        c = 0;
    }
    kill(info->si_pid, SIGUSR2);
}

int main(void)
{
    int                 pid;
    struct sigaction    siga;

    pid = getpid();
    siga.sa_sigaction = &siga_handler;
    sigemptyset(&siga.sa_mask);
    siga.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &siga, NULL);
    sigaction(SIGUSR2, &siga, NULL);
    sigaction(SIGINT, &siga, NULL);
    // aqui tem que fazer o write do PID
    write(1, "\n", 1);
    while (1)
    {
        ;
    }
    return 0;
}