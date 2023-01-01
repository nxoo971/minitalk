/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:56:08 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/13 22:56:10 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_total = 0;

void	send_signal(pid_t pid, unsigned int signal)
{
	if (kill(pid, signal) < 0)
	{
		ft_printf("Wrong pid, program exiting ..\n");
		exit(EXIT_FAILURE);
	}
}

void	encode(pid_t pid, unsigned char *encode)
{
	unsigned char	i;

	while (*encode)
	{
		i = 0x80;
		while (i)
		{
			g_total = 0;
			if (*encode & i)
				send_signal(pid, SIGUSR1);
			else
				send_signal(pid, SIGUSR2);
			while (!g_total)
				pause();
			i >>= 1;
		}
		encode++;
	}
}

void	send_null(pid_t pid)
{
	unsigned char	i;

	i = 0x80;
	while (i)
	{
		g_total = 0;
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_printf("Wrong pid, program exiting ..\n");
			exit(EXIT_FAILURE);
		}
		while (!g_total)
			pause();
		i >>= 1;
	}
}

void	handler(int signum, siginfo_t *client, void *ucontext)
{
	(void)ucontext;
	(void)client;
	if (signum == SIGUSR1)
		g_total = 1;
	else if (signum == SIGUSR2)
	{
		ft_printf("Datas has been received\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	pid_t		pid;
	t_saction	saction;

	ft_memset(& saction, 0, sizeof(saction));
	saction.sa_flags = SA_SIGINFO;
	saction.sa_sigaction = handler;
	sigaction(SIGUSR1, &saction, 0);
	sigaction(SIGUSR2, &saction, 0);
	if (ac == 3)
	{
		pid = parse_pid(av[1]);
		if (pid > 0)
		{
			encode(pid, (unsigned char *)av[2]);
			send_null(pid);
		}
		else
			ft_printf("Wrong pid, program exiting ..\n");
	}
	else
		ft_printf("usage: ./client [ProcessID] [message]\n");
	return (0);
}
