/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:22:12 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 11:08:57 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_good_one_high_and_push(t_stack *a, t_stack *b, int j, int k)
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
	push(a, b, 'b');
}

void	chunk_sort(t_stack *a, int nbr_chunk)
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
		put_good_one_high_and_push(a, &b, j * chunk, j * chunk + chunk);
		if (i == chunk)
		{
			i = 0;
			j++;
		}
		i++;
	}
	push_high_back_and_free(a, &b);
}
