/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:58:40 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/02 10:55:29 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(src) + ft_strlen(dst);
	if ((size_t)ft_strlen(dst) > dstsize - 1 || dstsize == 0)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (dst[i])
	{
		i++;
	}
	j = 0;
	while (src[j] && dstsize - 1 - i - j > 0)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (len);
}
