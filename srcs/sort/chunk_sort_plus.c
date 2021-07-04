/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:43:32 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 11:36:21 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_norm
{
	int		all_inf;
	int		all_sup;
}t_norm;

void	chunk_sort_plus(t_stack *a, int nbr_chunk)
{
	int		chunk;
	int		i;
	int		j;
	int		k;
	t_stack	b;

	init_stack(&b);
	chunk = a->size / nbr_chunk;
	i = 0;
	j = (int)floor(nbr_chunk / 2);
	k = (int)ceil(nbr_chunk / 2);
	if (j == k)
		k++;
	while (a->size != 0)
	{
		put_good_one_high_and_push_plus(a, &b, j * chunk, k * chunk);
		if (i == chunk)
		{
			i = 0;
			j--;
			k++;
		}
		i++;
	}
	push_high_back_and_free(a, &b);
}

void	put_good_one_high_and_push_plus(t_stack *a, t_stack *b, int j, int k)
{
	int	pos;
	int	pos2;

	pos = pos_next(a, j, k);
	pos2 = pos_prev(a, j, k);
	if (pos > pos2)
	{
		while (pos2-- > 0)
			reverse_rotate(a, 'a');
	}
	else
	{
		while (pos-- > 0)
			rotate(a, 'a');
	}
	check_and_push(a, b, a->first);
}

void	check_and_push(t_stack *a, t_stack *b, t_elem *elem)
{
	t_norm	norm;
	t_elem	*tmp;
	int		i;

	if (first_or_second_push(a, b) == 1)
		return ;
	norm.all_inf = 0;
	norm.all_sup = 0;
	i = -1;
	tmp = b->first;
	while (++i < b->size)
	{
		if (tmp->pos < elem->pos)
			norm.all_sup++;
		if (tmp->pos > elem->pos)
			norm.all_inf++;
		tmp = tmp->next;
	}
	if (norm.all_sup < norm.all_inf)
	{
		push(a, b, 'b');
		rotate(b, 'b');
	}
	else
		push(a, b, 'b');
}
