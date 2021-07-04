/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:51:08 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 13:37:01 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_high_back_and_free(t_stack *a, t_stack *b)
{
	while (b->size != 0)
	{
		put_max_high(b, 'b');
		push(b, a, 'a');
	}
	free_stack(b);
}

int	first_or_second_push(t_stack *a, t_stack *b)
{
	if (b->size == 0)
	{
		push(a, b, 'b');
		return (1);
	}
	if (b->size == 1)
	{
		if (b->first->pos > a->first->pos)
		{
			push(a, b, 'b');
			rotate(b, 'b');
		}
		else
			push(a, b, 'b');
		return (1);
	}
	return (0);
}

static int	find_smaller(t_step *step)
{
	if (step->chunk_sort_min < step->chunk_sort_plus_min \
	&& step->chunk_sort_min < step->chunk_sort_bside_min \
	&& step->chunk_sort_min < step->chunk_sort_plus_bside_min)
		return (1);
	if (step->chunk_sort_plus_min < step->chunk_sort_min \
	&& step->chunk_sort_plus_min < step->chunk_sort_bside_min \
	&& step->chunk_sort_plus_min < step->chunk_sort_plus_bside_min)
		return (2);
	if (step->chunk_sort_bside_min < step->chunk_sort_min \
	&& step->chunk_sort_bside_min < step->chunk_sort_plus_min \
	&& step->chunk_sort_bside_min < step->chunk_sort_plus_bside_min)
		return (3);
	if (step->chunk_sort_plus_bside_min < step->chunk_sort_min \
	&& step->chunk_sort_plus_bside_min < step->chunk_sort_plus_min \
	&& step->chunk_sort_plus_bside_min < step->chunk_sort_bside_min)
		return (4);
	return (1);
}

void	check_faster(t_stack *a, t_step *step)
{
	int	n;

	n = find_smaller(step);
	if (n == 1)
		chunk_sort(a, step->nbr_chunk_sort);
	else if (n == 2)
		chunk_sort_plus(a, step->nbr_chunk_plus);
	else if (n == 3)
		chunk_sort_bside(a, step->nbr_chunk_bside);
	else if (n == 4)
		chunk_sort_bside_plus(a, step->nbr_chunk_plus_bside);
}
