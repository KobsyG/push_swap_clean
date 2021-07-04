/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_and_five_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:22:49 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 11:26:47 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_sort(t_stack *a)
{
	if (a->first->n < a->first->next->n)
	{
		if (a->first->prev->n < a->first->n)
			reverse_rotate(a, 'a');
		else if (a->first->next->n > a->first->prev->n)
		{
			swap(a, 'a');
			rotate(a, 'a');
		}
	}
	else if (a->first->n < a->first->prev->n)
		swap(a, 'a');
	else if (a->first->next->n < a->first->prev->n)
		rotate(a, 'a');
	else if (a->first->next->n > a->first->prev->n)
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
}

void	five_sort(t_stack *a)
{
	t_stack	b;

	if (check_sort(a) == 0)
		return ;
	init_stack(&b);
	put_min_high(a, 'a');
	push(a, &b, 'b');
	put_min_high(a, 'a');
	push(a, &b, 'b');
	three_sort(a);
	push(&b, a, 'a');
	push(&b, a, 'a');
	free_stack(&b);
}
