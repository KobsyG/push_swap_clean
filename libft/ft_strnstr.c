/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:29:12 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/24 08:51:50 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			if (haystack[i + 1] != needle[j + 1] && needle[j + 1] != 0)
			{
				i = i - j;
				j = 0;
			}
			else
				j++;
			if (needle[j] == 0)
				return ((char *)&haystack[i - j + 1]);
		}
		i++;
	}
	return (NULL);
}
