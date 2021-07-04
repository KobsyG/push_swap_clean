/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:43:06 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 12:49:37 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_norm
{
	int	max;
	int	i;
}t_norm;

void	init_step(t_step *step)
{
	step->chunk_sort = 0;
	step->chunk_sort_min = -1;
	step->chunk_sort_plus = 0;
	step->chunk_sort_plus_min = -1;
	step->chunk_sort_bside = 0;
	step->chunk_sort_bside_min = -1;
	step->chunk_sort_plus_bside = 0;
	step->chunk_sort_plus_bside_min = -1;
	step->nbr_chunk_sort = -1;
	step->nbr_chunk_plus = -1;
	step->nbr_chunk_bside = -1;
	step->nbr_chunk_plus_bside = -1;
}

void	push_high_back_and_free_silent(t_stack *a, t_stack *b, int *step)
{
	while (b->size != 0)
	{
		put_max_high_silent(b, step);
		push_silent(b, a, step);
	}
	free_stack(b);
}

void	put_min_high_silent(t_stack *a, int *step)
{
	int		pos;
	int		min;
	int		i;
	t_elem	*elem;

	i = -1;
	min = a->first->n;
	elem = a->first;
	while (++i < a->size)
	{
		if (elem->n < min)
		{
			min = elem->n;
			pos = i;
		}
		elem = elem->next;
	}
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			rotate_silent(a, step);
		return ;
	}
	while (pos++ < a->size)
		reverse_rotate_silent(a, step);
}

void	put_max_high_silent(t_stack *a, int *step)
{
	t_norm	norm;
	int		pos;
	t_elem	*elem;

	norm.i = -1;
	norm.max = a->first->n;
	elem = a->first;
	pos = 0;
	while (++norm.i < a->size)
	{
		if (elem->n > norm.max)
		{
			norm.max = elem->n;
			pos = norm.i;
		}
		elem = elem->next;
	}
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			rotate_silent(a, step);
		return ;
	}
	while (pos++ < a->size)
		reverse_rotate_silent(a, step);
}

int	first_or_second_push_silent(t_stack *a, t_stack *b, int *step)
{
	if (b->size == 0)
	{
		push_silent(a, b, step);
		return (1);
	}
	if (b->size == 1)
	{
		if (b->first->pos > a->first->pos)
		{
			push_silent(a, b, step);
			rotate_silent(b, step);
		}
		else
			push_silent(a, b, step);
		return (1);
	}
	return (0);
}
