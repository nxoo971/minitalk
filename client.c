/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:55:21 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/19 05:08:11 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isspace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\f');
}

static int	ft_atoi(const char *str)
{
	int		neg;
	long	res;

	res = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * neg);
}

void	encode(int pid, unsigned char *encode)
{
	static const int signals[] = {SIGUSR2, SIGUSR1};
	while (*encode)
	{
		unsigned int i = 1 << 7;
		while (i)
		{
			kill(pid, signals[*encode & i ? 1 : 0]);
			i >>= 1;
			usleep(500);
		}
		encode++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		encode(ft_atoi(av[1]), (unsigned char *)av[2]);
	return (0);
}