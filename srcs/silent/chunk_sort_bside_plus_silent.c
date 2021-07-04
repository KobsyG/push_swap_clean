/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_bside_plus_silent.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:22:36 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 14:12:41 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	chunk_sort_bside_plus_silent(t_stack *a, int nbr_chunk, int *step)
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
		put_good_one_high_and_push_bside_silent(a, j * chunk, k * chunk, step);
		check_and_push_bside_silent(a, &b, a->first, step);
		if (i == chunk)
		{
			i = 0;
			j--;
			k++;
		}
		i++;
	}
	push_back_and_free_silent(a, &b, step);
}

void	push_back_and_free_silent(t_stack *a, t_stack *b, int *step)
{
	put_max_high_silent(b, step);
	while (b->size != 0)
		push_silent(b, a, step);
	free_stack(b);
}
