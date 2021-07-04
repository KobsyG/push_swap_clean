/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:35:02 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/03 13:40:15 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_elem	*elem;
	t_elem	*tmp;
	int		i;

	i = 0;
	elem = a->first;
	i = 0;
	while (i++ < a->size)
	{
		tmp = elem->next;
		free(elem);
		elem = NULL;
		elem = tmp;
	}
}

int	parsing(int ac, char **av, t_stack *a)
{
	int		i;
	int		j;
	long	nbr;
	int		signe;

	init_stack(a);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			nbr = 0;
			signe = 1;
			while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
				j++;
			if (av[i][j] == '-')
			{
				signe = -1;
				j++;
			}
			while (av[i][j] >= '0' && av[i][j] <= '9')
			{
				nbr = nbr * 10 + (av[i][j] - 48);
				j++;
			}
			if ((av[i][j] > '9' || av[i][j] < '0') && (av[i][j] != ' ' && av[i][j] != 0))
				return (-1);
			if (nbr < -2147483648 || nbr > 2147483647)
				return (-1);
			insert_elem_list(a, (int)nbr * signe);
		}
	}
	return (0);
}

int	verif_doubl(t_stack *stack)
{
	int		tab[stack->size];
	int		i;
	int		j;
	t_elem	*elem;

	elem = stack->first;
	tab[0] = 0;
	i = -1;
	while (++i < stack->size)
	{
		j = -1;
		while (++j < i)
		{
			if (tab[j] == elem->n)
				return (-1);
		}
		tab[j] = elem->n;
		elem = elem->next;
	}
	return (0);
}
