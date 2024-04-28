/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:30:27 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/04/24 19:26:59 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char_bonus(int pid, unsigned char let)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((let >> bit) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		write(1, "\nWell Done!\n\n", 13);
	exit(0);
}

int	main(int ac, char **av)
{
	int				i;
	static int		pid;
	unsigned char	*str;

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
