/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:55:21 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/19 05:12:21 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		nb = n * -1;
		ft_putchar('-');
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	tst(int signalnum)
{
	static const unsigned int	pow[] = {1, 2, 4, 8, 16, 32, 64, 128};
	static int nsig = 7;
	static unsigned char c = 0;
	if (signalnum > 0)
	{
		if (signalnum == SIGUSR1)
			c += pow[nsig];
		nsig--;
	}
	if (nsig == -1)
	{
		ft_putchar(c);
		c = 0;
		nsig = 7;
	}
	usleep(100);
}


int	main(int ac, char **av)
{
	ft_putnbr(getpid());
	signal(SIGUSR1, tst);
	signal(SIGUSR2, tst);
	while (42)
		;
	return (0);
}
