/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:25:19 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 11:08:38 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c)
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
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push(t_stack *a, t_stack *b, char c)
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
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack *stack, char c)
{
	stack->first = stack->first->next;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack *stack, char c)
{
	stack->first = stack->first->prev;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
