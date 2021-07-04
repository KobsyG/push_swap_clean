/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:25:36 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/24 10:18:48 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	s2 = ft_strdup(s);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s2[i])
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	return (s2);
}
