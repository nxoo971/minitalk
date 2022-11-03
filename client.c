/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:55:21 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/21 01:15:31 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define TERNARY(a, b) (a & b ? 1 : 0)

static \
void	usage(void)
{
	ft_putstr("usage: ./program_name [ProcessID] [message]\n");
}

void	encode(int pid, unsigned char *encode)
{
	static const int	signals[] = {SIGUSR2, SIGUSR1};
	unsigned int		i;

	while (*encode)
	{
		i = 1 << 7;
		while (i)
		{
			if (kill(pid, signals[TERNARY(*encode, i)]) < 0)
			{
				ft_putstr("Wrong pid, program exiting ..\n");
				return ;
			}
			i >>= 1;
			usleep(200);
		}
		encode++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		encode(ft_atoi(av[1]), (unsigned char *)av[2]);
	else
		usage();
	return (0);
}
