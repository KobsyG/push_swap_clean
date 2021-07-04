/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:37:49 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/02 10:55:52 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	isstart(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (isset(s1[i], set) == 1)
	{
		i++;
	}
	return (i);
}

static int	isend(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (isset(s1[i], set) == 1)
	{
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*s2;

	start = isstart(s1, set);
	if (start == (size_t)ft_strlen(s1))
	{
		if (ft_salloc(&s2, sizeof(char)))
			return (NULL);
		s2[0] = 0;
		return (s2);
	}
	end = isend(s1, set);
	if (ft_salloc(&s2, sizeof(char) * (end - start + 2)))
		return (NULL);
	i = 0;
	while (start <= end)
	{
		s2[i] = s1[start];
		i++;
		start++;
	}
	s2[i] = 0;
	return (s2);
}
