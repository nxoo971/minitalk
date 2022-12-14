/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:28:10 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/14 23:06:02 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_unsigned(uintptr_t nb, const int base)
{
	static int	len;

	len = 0;
	if (nb >= (unsigned)base)
		len_unsigned(nb / (unsigned)base, base);
	len++;
	return (len);
}

int	len_integer(intptr_t nb, const int base)
{
	if (nb < 0)
		return (1 + len_unsigned((unsigned)nb * -1, base));
	return (len_unsigned((unsigned)nb, base));
}
