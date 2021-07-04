/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_silent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:41:07 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 13:58:26 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_good_one_high_and_push_silent(t_stack *a, int j, int k, int *step)
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

void	chunk_sort_silent(t_stack *a, int nbr_chunk, int *step)
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
		put_good_one_high_and_push_silent(a, j * chunk, \
		j * chunk + chunk, step);
		push_silent(a, &b, step);
		if (i == chunk)
		{
			i = 0;
			j++;
		}
		i++;
	}
	push_high_back_and_free_silent(a, &b, step);
}
