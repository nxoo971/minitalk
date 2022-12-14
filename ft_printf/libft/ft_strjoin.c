/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooxn <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:25:53 by ooxn              #+#    #+#             */
/*   Updated: 2022/09/07 21:25:54 by ooxn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dst, const char *src)
{
	char	*start;

	start = dst;
	while (*start)
		start++;
	while (*src)
		*start++ = *src++;
	*start = 0;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	strjoin = malloc(size_s1 + size_s2 + 1);
	if (strjoin)
	{
		*strjoin = 0;
		ft_strcat(strjoin, s1);
		ft_strcat(strjoin, s2);
	}
	return (strjoin);
}
