/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_plus_silent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:54:21 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 14:08:00 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_norm
{
	int		all_inf;
	int		all_sup;
}t_norm;

void	chunk_sort_plus_silent(t_stack *a, int nbr_chunk, int *step)
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
		put_good_one_high_push_plus_silent(a, j * chunk, k * chunk, step);
		check_and_push_silent(a, &b, a->first, step);
		if (i == chunk)
		{
			i = 0;
			j--;
			k++;
		}
		i++;
	}
	push_high_back_and_free_silent(a, &b, step);
}

void	put_good_one_high_push_plus_silent(t_stack *a, int j, int k, int *step)
{
	int	pos;
	int	pos2;

	pos = pos_next(a, j, k);
	pos2 = pos_prev(a, j, k);
	if (pos > pos2)
	{
		while (pos2-- > 0)
			reverse_rotate_silent(a, step);
	}
	else
	{
		while (pos-- > 0)
			rotate_silent(a, step);
	}
}

void	check_and_push_silent(t_stack *a, t_stack *b, t_elem *elem, int *step)
{
	t_norm	norm;
	t_elem	*tmp;
	int		i;

	if (first_or_second_push_silent(a, b, step) == 1)
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
		push_silent(a, b, step);
		rotate_silent(b, step);
	}
	else
		push_silent(a, b, step);
}
