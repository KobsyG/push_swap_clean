/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:11:13 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/12 18:16:25 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_tri(t_stack *a)
{
	t_elem	*elem;
	int		i;

	elem = a->first;
	i = 0;
	while (++i < a->size)
	{
		if (elem->pos > elem->next->pos)
		{
			write(1, "KO\n", 3);
			return ;
		}
		elem = elem->next;
	}
	write(1, "OK\n", 3);
}

int	check_line(t_stack *a)
{
	t_stack	b;
	int		check;
	char	*line;

	init_stack(&b);
	while (get_next_line(0, &line) != 0)
	{		
		check = 4;
		check = check + check_swap(line, a, &b);
		check = check + check_push(line, a, &b);
		check = check + check_rotate(line, a, &b);
		check = check + check_reverse_rotate(line, a, &b);
		if (check == 0)
		{
			write(2, "Error\n", 6);
			free_stack(a);
			free_stack(&b);
			return (-1);
		}
	}
	free_stack(&b);
	return (0);
}
