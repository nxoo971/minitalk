/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:26:33 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/13 22:00:10 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	parse_pid(const char *s)
{
	const char	*begin;

	begin = s;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
		{
			ft_printf("Wrong pid, program exiting ..\n");
			exit(EXIT_FAILURE);
		}
		s++;
	}
	return (ft_atoi(begin));
}

void	ft_strjoin2(char **line, const char *s1)
{
	char	*res;
	int		i;

	if (*line && **line)
	{
		i = 0;
		while ((*line)[i])
			i++;
		res = malloc(ft_strlen(*line) + i + 1);
		if (res)
		{
			ft_strcpy(res, *line);
			ft_strcpy(res + i, s1);
			free(*line);
			*line = res;
		}
		return ;
	}
	if (*line && !**line)
		free(*line);
	*line = ft_strdup(s1);
}
