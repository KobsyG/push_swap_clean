/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:26:38 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 11:38:58 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_norm
{
	int	max;
	int	i;
	int	min;
	int	min1;
	int	min2;
}t_norm;

int	pos_next(t_stack *a, int j, int k)
{
	int		pos;
	t_elem	*elem;

	pos = 0;
	elem = a->first;
	while (elem->pos < j || elem->pos > k)
	{
		elem = elem->next;
		pos++;
	}
	return (pos);
}

int	pos_prev(t_stack *a, int j, int k)
{
	int		pos;
	t_elem	*elem;

	elem = a->first;
	pos = 0;
	while (elem->pos < j || elem->pos > k)
	{
		elem = elem->prev;
		pos++;
	}
	return (pos);
}

void	get_min_and_max(t_stack *a, int *min, int *max)
{
	t_norm	norm;
	int		max1;
	t_elem	*elem;

	elem = a->first;
	norm.min1 = a->first->n;
	max1 = a->first->n;
	a->first->pos = 0;
	norm.i = -1;
	while (++norm.i < a->size)
	{
		if (elem->n < norm.min1)
		{
			elem->pos = 0;
			norm.min1 = elem->n;
		}
		if (elem->n > max1)
		{
			elem->pos = a->size - 1;
			max1 = elem->n;
		}
		elem = elem->next;
	}
	*max = max1;
	*min = norm.min1;
}

void	put_min_high(t_stack *a, char c)
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
			rotate(a, c);
		return ;
	}
	while (pos++ < a->size)
		reverse_rotate(a, c);
}

void	put_max_high(t_stack *a, char c)
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
			rotate(a, c);
		return ;
	}
	while (pos++ < a->size)
		reverse_rotate(a, c);
}
