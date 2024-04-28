/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:14:49 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/04/20 16:31:39 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

unsigned char	*g_whole_msg_b = NULL;

static void	drop_msg_b(unsigned char bit)
{
	if (bit == 0)
	{
		write(1, g_whole_msg_b, ft_strlen(g_whole_msg_b));
		write(1, "\n", 1);
		free(g_whole_msg_b);
		g_whole_msg_b = NULL;
	}
	else
		g_whole_msg_b = ft_strjoin(g_whole_msg_b, bit);
}

static void	siga_handler_bonus(int signal, siginfo_t *info, void *context)
{
	static unsigned char	bit;
	static unsigned char	bit_pos;

	(void)context;
	if (signal == SIGUSR2)
		bit |= (0x01 << bit_pos);
	bit_pos++;
	if (bit_pos == 8)
	{
		drop_msg_b(bit);
		if (bit == '\0')
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		bit_pos = 0;
	}
	if (signal == SIGINT)
	{
		if (g_whole_msg_b)
			free(g_whole_msg_b);
		write(1, "\nTchau\n", 7);
		exit(EXIT_SUCCESS);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	siga;

	pid = getpid();
	siga.sa_sigaction = &siga_handler_bonus;
	siga.sa_flags = SA_SIGINFO;
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	sigaction(SIGINT, &siga, NULL);
	while (1)
		usleep(50);
	return (EXIT_SUCCESS);
}
