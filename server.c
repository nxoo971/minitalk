/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:56:13 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/13 22:56:16 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	alloc(char **dst, char *src)
{
	ft_strjoin2(dst, src);
	if (!*dst)
	{
		ft_memdel((void **)dst);
		exit(EXIT_FAILURE);
	}
}

void	tst(int signum, siginfo_t *client, void *context)
{
	static int				nsig = -42;
	static char				*word = 0;
	static unsigned char	c = 0;

	(void)context;
	if (nsig == -42)
		nsig = 7;
	if (signum == SIGUSR1)
		c += (1 << nsig);
	nsig--;
	if (nsig < 0 && c)
	{
		alloc(& word, (char *)& c);
		c = 0;
		nsig = -42;
	}
	else if (nsig < 0 && !c)
	{
		ft_printf("%s", word);
		kill(client->si_pid, SIGUSR2);
		ft_memdel((void **)& word);
		nsig = -42;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	t_saction	saction;

	ft_printf("%d\n", getpid());
	ft_memset(& saction, 0, sizeof(saction));
	saction.sa_flags = SA_SIGINFO;
	saction.sa_sigaction = tst;
	sigaction(SIGUSR1, &saction, 0);
	sigaction(SIGUSR2, &saction, 0);
	while (42)
		pause();
	return (0);
}
