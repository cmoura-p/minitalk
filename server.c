/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:55:08 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/04/20 16:31:58 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_whole_msg = NULL;

static void	drop_msg(unsigned char bit)
{
	if (bit == 0)
	{
		write(1, g_whole_msg, ft_strlen(g_whole_msg));
		write(1, "\n", 1);
		free(g_whole_msg);
		g_whole_msg = NULL;
	}
	else
		g_whole_msg = ft_strjoin(g_whole_msg, bit);
}

static void	siga_handler(int signal)
{
	static int				bit_pos;
	static unsigned char	bit;

	if (signal == SIGUSR2)
		bit |= (0x01 << bit_pos);
	bit_pos++;
	if (bit_pos == 8)
	{
		drop_msg(bit);
		bit = 0;
		bit_pos = 0;
	}
	if (signal == SIGINT)
	{
		if (g_whole_msg)
			free(g_whole_msg);
		write(1, "\nTchau\n", 7);
		exit(EXIT_SUCCESS);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	siga;

	pid = getpid();
	siga.sa_handler = &siga_handler;
	sigemptyset(&siga.sa_mask);
	siga.sa_flags = 0;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	sigaction(SIGINT, &siga, NULL);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		usleep(50);
	return (EXIT_SUCCESS);
}
