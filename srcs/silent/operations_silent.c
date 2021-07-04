/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_silent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:34:51 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 06:31:33 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_silent(t_stack *stack, int *step)
{
	int	ntmp;
	int	postmp;

	if (stack->size <= 1)
		return ;
	ntmp = stack->first->n;
	postmp = stack->first->pos;
	stack->first->n = stack->first->next->n;
	stack->first->pos = stack->first->next->pos;
	stack->first->next->n = ntmp;
	stack->first->next->pos = postmp;
	(*step)++;
}

void	push_silent(t_stack *a, t_stack *b, int *step)
{
	t_elem	*tmp;

	if (a->size == 0)
		return ;
	tmp = a->first;
	a->first->prev->next = a->first->next;
	a->first->next->prev = a->first->prev;
	a->first = a->first->next;
	a->size--;
	if (b->size == 0)
	{
		insert_elem_list(b, tmp->n);
		b->first->pos = tmp->pos;
	}
	else
	{
		b->first->prev->next = tmp;
		tmp->next = b->first;
		tmp->prev = b->first->prev;
		b->first->prev = tmp;
		b->first = tmp;
		b->size++;
	}
	(*step)++;
}

void	rotate_silent(t_stack *stack, int *step)
{
	stack->first = stack->first->next;
	(*step)++;
}

void	reverse_rotate_silent(t_stack *stack, int *step)
{
	stack->first = stack->first->prev;
	(*step)++;
}
