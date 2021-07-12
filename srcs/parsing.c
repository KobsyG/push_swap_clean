/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:35:02 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/12 19:14:50 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_norm
{
	int	nbr;
	int	i;
	int	signe;
}t_norm;

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

static int	push_swap_atoi(char *str, t_stack *a)
{
	t_norm	norm;

	norm.i = 0;
	while (str[norm.i])
	{
		norm.nbr = 0;
		norm.signe = 1;
		while ((str[norm.i] >= 9 && str[norm.i] <= 13) || str[norm.i] == 32)
			norm.i++;
		if (str[norm.i] == '-')
		{
			norm.signe = -1;
			norm.i++;
		}
		while (str[norm.i] >= '0' && str[norm.i] <= '9')
		{
			norm.nbr = norm.nbr * 10 + (str[norm.i] - 48);
			norm.i++;
		}
		if (((str[norm.i] > '9' || str[norm.i] < '0') && (str[norm.i] != ' ' && \
		str[norm.i] != 0)) || norm.nbr < -2147483648 || norm.nbr > 2147483647)
			return (-1);
		insert_elem_list(a, (int)norm.nbr * norm.signe);
	}
	return (0);
}

int	parsing(int ac, char **av, t_stack *a)
{
	int	i;
	int	j;

	init_stack(a);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (push_swap_atoi(&av[i][j], a) == -1)
			return (-1);
	}
	return (0);
}

int	verif_doubl(t_stack *stack)
{
	int		*tab;
	int		i;
	int		j;
	t_elem	*elem;

	if (ft_salloc_int(&tab, sizeof(int) * stack->size) == 1)
		return (-1);
	elem = stack->first;
	i = -1;
	while (++i < stack->size)
	{
		j = -1;
		while (++j < i)
		{
			if (tab[j] == elem->n)
			{
				free(tab);
				return (-1);
			}
		}
		tab[j] = elem->n;
		elem = elem->next;
	}
	free(tab);
	return (0);
}
