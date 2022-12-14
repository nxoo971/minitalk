/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:56:18 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/13 22:56:20 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# include "ft_printf/ft_printf.h"

typedef struct sigaction	t_saction;

int		parse_pid(const char *s);
void	ft_strjoin2(char **line, const char *s1);

#endif
