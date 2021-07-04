/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_bside_silent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:44:42 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 13:56:56 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_norm
{
	t_elem	*elem;
	t_elem	*tmp;
	int		all_inf;
	int		all_sup;
	int		i;
	int		j;
	int		next;
}t_norm;

void	chunk_sort_bside_silent(t_stack *a, int nbr_chunk, int *step)
{
	int		chunk;
	int		i;
	int		j;
	t_stack	b;

	init_stack(&b);
	chunk = a->size / nbr_chunk;
	i = 0;
	j = 0;
	while (a->size != 0)
	{
		put_good_one_high_and_push_bside_silent(a, j * chunk, \
		j * chunk + chunk, step);
		check_and_push_bside_silent(a, &b, a->first, step);
		if (i == chunk)
		{
			i = 0;
			j++;
		}
		i++;
	}
	put_max_high_silent(&b, step);
	while (b.size != 0)
		push_silent(&b, a, step);
	free_stack(&b);
}

void	put_good_one_high_and_push_bside_silent(t_stack *a, int j, \
int k, int *step)
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

void	check_and_push_bside_silent(t_stack *a, t_stack *b, \
t_elem *elem, int *step)
{
	t_norm	norm;

	if (first_or_second_push_silent(a, b, step) == 1)
		return ;
	norm.i = -1;
	norm.all_inf = 0;
	norm.all_sup = 0;
	norm.tmp = b->first;
	while (++norm.i < b->size)
	{
		if (norm.tmp->pos < elem->pos)
			norm.all_sup++;
		if (norm.tmp->pos > elem->pos)
			norm.all_inf++;
		norm.tmp = norm.tmp->next;
	}
	if (norm.all_inf == 0)
		put_min_high_silent(b, step);
	if (norm.all_sup == 0)
		put_max_high_silent(b, step);
	else
		put_next_elem_high_silent(b, step, elem->pos);
	push_silent(a, b, step);
}

void	put_next_elem_high_silent(t_stack *a, int *step, int pos)
{
	t_norm	norm;

	norm.elem = a->first;
	norm.i = -1;
	norm.j = -1;
	norm.next = -1;
	while (++norm.i < a->size)
	{
		if (norm.elem->pos > norm.next && norm.elem->pos < pos)
		{
			norm.next = norm.elem->pos;
			norm.j = norm.i;
		}
		norm.elem = norm.elem->next;
	}
	if (norm.j == -1)
		put_max_high_silent(a, step);
	if (norm.j <= a->size / 2)
	{
		while (norm.j-- > 0)
			rotate_silent(a, step);
		return ;
	}
	while (norm.j++ < a->size)
		reverse_rotate_silent(a, step);
}
