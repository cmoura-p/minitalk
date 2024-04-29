/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:54:47 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/04/24 19:10:05 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((c >> bit) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int				pid;
	int				i;
	unsigned char	*str;

	if (ac == 2)
	{
		str = (unsigned char *)av[2];
		pid = ft_atoi(av[1]);
		i = 0;
		while (str[i])
		{
			send_char(pid, str[i]);
			i++;
		}
		send_char(pid, '\0');
	}
	else
	{
		write(1, "You must type the pid and the message\n", 39);
		write(1, "./client [PID] [MESSAGE]\n", 25);
	}
	return (0);
}
