/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:45:52 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/12 19:18:31 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_swap(char *line, t_stack *a, t_stack *b)
{
	int	ul;

	if (line[0] == 's')
	{
		if (line[1] == 'a' && line[2] == 0)
		{
			swap_silent(a, &ul);
			return (1);
		}
		else if (line[1] == 'b' && line[2] == 0)
		{
			swap_silent(b, &ul);
			return (1);
		}
		else if (line[1] == 's' && line[2] == 0)
		{
			swap_silent(a, &ul);
			swap_silent(b, &ul);
			return (1);
		}
	}
	return (-1);
}

int	check_push(char *line, t_stack *a, t_stack *b)
{
	int	ul;

	if (line[0] == 'p')
	{
		if (line[1] == 'a' && line[2] == 0)
		{
			push_silent(b, a, &ul);
			return (1);
		}
		else if (line[1] == 'b' && line[2] == 0)
		{
			push_silent(a, b, &ul);
			return (1);
		}
	}
	return (-1);
}

int	check_rotate(char *line, t_stack *a, t_stack *b)
{
	int	ul;

	if (line[0] == 'r')
	{
		if (line[1] == 'a' && line[2] == 0)
		{
			rotate_silent(a, &ul);
			return (1);
		}
		else if (line[1] == 'b' && line[2] == 0)
		{
			rotate_silent(b, &ul);
			return (1);
		}
		else if (line[1] == 'r' && line[2] == 0)
		{
			rotate_silent(a, &ul);
			rotate_silent(b, &ul);
			return (1);
		}
	}
	return (-1);
}

int	check_reverse_rotate(char *line, t_stack *a, t_stack *b)
{
	int	ul;

	if (line[0] == 'r' && line[1] == 'r')
	{
		if (line[2] == 'a' && line[3] == 0)
		{
			reverse_rotate_silent(a, &ul);
			return (1);
		}
		else if (line[2] == 'b' && line[3] == 0)
		{
			reverse_rotate_silent(b, &ul);
			return (1);
		}
		else if (line[2] == 'r' && line[3] == 0)
		{
			reverse_rotate_silent(a, &ul);
			reverse_rotate_silent(b, &ul);
			return (1);
		}
	}
	return (-1);
}

int	main(int ac, char **av)
{
	t_stack	a;

	if (ac == 1)
		return (0);
	if (verif_doubl(&a) == -1 || parsing(ac, av, &a) == -1)
	{
		free_stack(&a);
		write(2, "Error\n", 6);
		return (-1);
	}
	get_pos(&a);
	if (check_line(&a) != 0)
		return (-1);
	check_tri(&a);
	free_stack(&a);
	return (0);
}
