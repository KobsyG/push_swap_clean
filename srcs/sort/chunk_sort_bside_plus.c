/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_bside_plus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:03:16 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 11:04:58 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	chunk_sort_bside_plus(t_stack *a, int nbr_chunk)
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
		put_good_one_high_and_push_bside(a, &b, j * chunk, k * chunk);
		if (i == chunk)
		{
			i = 0;
			j--;
			k++;
		}
		i++;
	}
	push_back_and_free(a, &b);
}

void	push_back_and_free(t_stack *a, t_stack *b)
{
	put_max_high(b, 'b');
	while (b->size != 0)
		push(b, a, 'a');
	free_stack(b);
}
