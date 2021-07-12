/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:04:45 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/12 19:37:44 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_sort(t_stack *a, t_step *step)
{
	t_stack	new;
	int		i;

	i = 0;
	while (++i < a->size)
	{
		copy_stack(a, &new);
		step->chunk_sort = 0;
		chunk_sort_silent(&new, i, &step->chunk_sort);
		if (step->chunk_sort < step->chunk_sort_min || \
		step->chunk_sort_min == -1)
		{
			step->chunk_sort_min = step->chunk_sort;
			step->nbr_chunk_sort = i;
		}
		free_stack(&new);
	}
}

void	count_sort_plus(t_stack *a, t_step *step)
{
	t_stack	new;
	int		i;

	i = 2;
	while (++i < a->size)
	{
		copy_stack(a, &new);
		step->chunk_sort_plus = 0;
		chunk_sort_plus_silent(&new, i, &step->chunk_sort_plus);
		if (step->chunk_sort_plus < step->chunk_sort_plus_min || \
		step->chunk_sort_plus_min == -1)
		{
			step->chunk_sort_plus_min = step->chunk_sort_plus;
			step->nbr_chunk_plus = i;
		}
		free_stack(&new);
	}
}

void	count_sort_bside(t_stack *a, t_step *step)
{
	t_stack	new;
	int		i;

	i = 2;
	while (++i < a->size)
	{
		copy_stack(a, &new);
		step->chunk_sort_bside = 0;
		chunk_sort_bside_silent(&new, i, &step->chunk_sort_bside);
		if (step->chunk_sort_bside < step->chunk_sort_bside_min || \
		step->chunk_sort_bside_min == -1)
		{
			step->chunk_sort_bside_min = step->chunk_sort_bside;
			step->nbr_chunk_bside = i;
		}
		free_stack(&new);
	}
}

void	count_sort_bside_plus(t_stack *a, t_step *step)
{
	t_stack	new;
	int		i;

	i = 2;
	while (++i < a->size)
	{
		copy_stack(a, &new);
		step->chunk_sort_plus_bside = 0;
		chunk_sort_bside_plus_silent(&new, i, &step->chunk_sort_plus_bside);
		if (step->chunk_sort_plus_bside < step->chunk_sort_plus_bside_min || \
		step->chunk_sort_plus_bside_min == -1)
		{
			step->chunk_sort_plus_bside_min = step->chunk_sort_plus_bside;
			step->nbr_chunk_plus_bside = i;
		}
		free_stack(&new);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_step	step;

	if (ac == 1)
		return (0);
	if (parsing(ac, av, &a) == -1 || verif_doubl(&a) == -1)
	{
		free_stack(&a);
		write(2, "Error\n", 6);
		return (-1);
	}
	init_step(&step);
	get_pos(&a);
	if (check_sort(&a) == 0)
	{
		free_stack(&a);
		return (0);
	}
	if (a.size == 3)
		three_sort(&a);
	else if (a.size == 5)
		five_sort(&a);
	else
		check_all_sort(&a, &step);
	free_stack(&a);
}
