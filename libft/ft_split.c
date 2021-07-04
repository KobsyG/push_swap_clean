/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:00:27 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/24 10:44:06 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_nbr_word(const char *s, char *charset)
{
	int	i;
	int	word;

	i = 0;
	word = 1;
	while (is_sep(s[i], charset) == 0)
		i++;
	if (s[i] == 0)
		return (0);
	while (s[i])
	{
		if (is_sep(s[i], charset) == 0 && is_sep(s[i + 1], charset) == 1
			&& s[i + 1] != 0)
			word++;
		i++;
	}
	return (word);
}

char	**ft_split(const char *s, char *charset)
{
	char	**tab;
	int		i;
	int		word;
	int		start;
	int		nbr_word;

	nbr_word = ft_nbr_word(s, charset);
	if (ft_talloc(&tab, sizeof(char *) * (nbr_word + 1)))
		return (NULL);
	tab[nbr_word] = NULL;
	if (nbr_word == 0)
		return (tab);
	i = 0;
	word = -1;
	while (++word < nbr_word)
	{
		while (is_sep(s[i], charset) == 0 && s[i])
			i++;
		start = i;
		while (is_sep(s[i], charset) == 1 && s[i])
			i++;
		tab[word] = ft_substr(s, start, i - start);
	}
	return (tab);
}
