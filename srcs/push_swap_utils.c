/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:53:06 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 11:32:15 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_norm
{
	int	max;
	int	i;
	int	min;
	int	min2;
}t_norm;

void	init_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->size = 0;
}

int	insert_elem_list(t_stack *stack, int n)
{
	t_elem	*elem;
	t_elem	*tmp;

	elem = malloc(sizeof(t_elem));
	elem->n = n;
	if (stack->size == 0)
	{
		elem->next = elem;
		elem->prev = elem;
		stack->first = elem;
		stack->size++;
		return (0);
	}
	stack->first->prev = elem;
	tmp = stack->first;
	while (tmp->next != stack->first)
		tmp = tmp->next;
	elem->prev = tmp;
	tmp->next = elem;
	elem->next = stack->first;
	stack->size++;
	return (0);
}

// int	check_sort(t_stack *a)
// {
// 	t_elem	*elem;
// 	int		i;

// 	elem = a->first;
// 	i = 0;
// 	while (++i < a->size)
// 	{
// 		if (elem->pos > elem->next->pos)
// 			return (1);
// 		elem = elem->next;
// 	}
// 	return (0);
// }

// void	print_stack(t_stack *stack, char c) //print stack
// {
// 	t_elem	*elem;
// 	int		i;

// 	i = -1;
// 	elem = stack->first;
// 	printf("------%c----\n", c);
// 	while (++i < stack->size)
// 	{
// 		printf("%d pos -> %d\n", elem->n, elem->pos);
// 		elem = elem->next;
// 	}
// 	printf("-----------\n");
// }

void	get_pos(t_stack *a)
{
	t_norm	norm;
	t_elem	*elem;
	int		j;

	norm.i = 1;
	get_min_and_max(a, &norm.min, &norm.max);
	elem = a->first;
	while (norm.i < a->size)
	{
		norm.min2 = norm.max;
		j = -1;
		while (++j < a->size)
		{			
			if (elem->n <= norm.min2 && elem->n > norm.min)
			{
				elem->pos = norm.i;
				norm.min2 = elem->n;
			}
			elem = elem->next;
		}
		norm.min = norm.min2;
		elem = elem->next;
		norm.i++;
	}
}

void	copy_stack(t_stack *stack, t_stack *new)
{
	int		i;
	t_elem	*elem;

	init_stack(new);
	elem = stack->first;
	i = 0;
	while (i < stack->size)
	{
		insert_elem_list(new, elem->n);
		elem = elem->next;
		i++;
	}
	get_pos(new);
}

int	check_sort(t_stack *a)
{
	t_elem	*elem;
	int		i;

	elem = a->first;
	i = 0;
	while (++i < a->size)
	{
		if (elem->pos > elem->next->pos)
			return (1);
		elem = elem->next;
	}
	return (0);
}
