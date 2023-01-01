/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:49:48 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/17 03:19:16 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_binary(va_list *param, struct s_spec_info *s)
{
	uintptr_t	n;

	n = va_arg(*param, unsigned int);
	s->current_size = len_unsigned(n, 2);
	s->is_null = n == 0;
	return (print_algo_flag(s, n, 2, faux));
}
