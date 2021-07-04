/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:05:30 by gbeco             #+#    #+#             */
/*   Updated: 2021/01/09 13:11:30 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tpn;

	if (!del)
		return ;
	while (*lst)
	{
		tpn = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = tpn;
	}
	lst = NULL;
}
