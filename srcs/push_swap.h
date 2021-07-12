/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:05:06 by gbeco             #+#    #+#             */
/*   Updated: 2021/07/12 19:30:42 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

# include <stdio.h> //printf

typedef struct s_elem
{
	int				n;
	int				pos;
	struct s_elem	*next;
	struct s_elem	*prev;	
}	t_elem;

typedef struct s_stack
{
	t_elem	*first;
	int		size;
}	t_stack;

typedef struct s_step
{
	int	chunk_sort;
	int	chunk_sort_min;
	int	chunk_sort_plus;
	int	chunk_sort_plus_min;
	int	chunk_sort_bside;
	int	chunk_sort_bside_min;
	int	chunk_sort_plus_bside;
	int	chunk_sort_plus_bside_min;
	int	nbr_chunk_sort;
	int	nbr_chunk_plus;
	int	nbr_chunk_bside;
	int	nbr_chunk_plus_bside;
}t_step;

//parsing
int		verif_doubl(t_stack *stack);
int		parsing(int ac, char **av, t_stack *a);

//utils
void	init_stack(t_stack *stack);
int		insert_elem_list(t_stack *stack, int n);
void	free_stack(t_stack *a);
void	get_pos(t_stack *a);
void	copy_stack(t_stack *stack, t_stack *new);
int		check_sort(t_stack *a);

//sort_silent
void	chunk_sort_silent(t_stack *a, int nbr_chunk, int *step);
void	chunk_sort_plus_silent(t_stack *a, int nbr_chunk, int *step);
void	chunk_sort_bside_silent(t_stack *a, int nbr_chunk, int *step);
void	chunk_sort_bside_plus_silent(t_stack *a, int nbr_chunk, int *step);
void	count_sort(t_stack *a, t_step *step);
void	count_sort_plus(t_stack *a, t_step *step);
void	count_sort_bside(t_stack *a, t_step *step);
void	count_sort_bside_plus(t_stack *a, t_step *step);

//operations_silent
void	swap_silent(t_stack *stack, int *step);
void	push_silent(t_stack *a, t_stack *b, int *step);
void	rotate_silent(t_stack *stack, int *step);
void	reverse_rotate_silent(t_stack *stack, int *step);

//silent
void	init_step(t_step *step);
void	put_good_one_high_and_push_silent(t_stack *a, int j, int k, int *step);
void	push_high_back_and_free_silent(t_stack *a, t_stack *b, int *step);
void	put_min_high_silent(t_stack *a, int *step);
void	put_max_high_silent(t_stack *a, int *step);
void	put_good_one_high_and_push_bside_silent(t_stack *a, int j, \
int k, int *step);
void	check_and_push_bside_silent(t_stack *a, t_stack *b, \
t_elem *elem, int *step);
int		first_or_second_push_silent(t_stack *a, t_stack *b, int *step);
void	put_next_elem_high_silent(t_stack *a, int *step, int pos);
void	put_good_one_high_push_plus_silent(t_stack *a, \
int j, int k, int *step);
void	check_and_push_silent(t_stack *a, t_stack *b, t_elem *elem, int *step);
void	push_back_and_free_silent(t_stack *a, t_stack *b, int *step);

//sort_utils
void	put_good_one_high_and_push(t_stack *a, t_stack *b, int j, int k);
void	put_good_one_high_and_push_plus(t_stack *a, t_stack *b, int j, int k);
void	put_good_one_high_and_push_bside(t_stack *a, t_stack *b, int j, int k);
void	get_min_and_max(t_stack *a, int *min, int *max);
int		pos_prev(t_stack *a, int j, int k);
int		pos_next(t_stack *a, int j, int k);
void	put_max_high(t_stack *a, char c);
void	put_min_high(t_stack *a, char c);
void	check_and_push(t_stack *a, t_stack *b, t_elem *elem);
void	check_and_push_bside(t_stack *a, t_stack *b, t_elem *elem);
void	push_high_back_and_free(t_stack *a, t_stack *b);
void	put_next_elem_high(t_stack *a, char c, int pos);
void	push_back_and_free(t_stack *a, t_stack *b);
int		first_or_second_push(t_stack *a, t_stack *b);

//sort
void	three_sort(t_stack *a);
void	five_sort(t_stack *a);
void	chunk_sort(t_stack *a, int nbr_chunk);
void	chunk_sort_plus(t_stack *a, int nbr_chunk);
void	chunk_sort_bside(t_stack *a, int nbr_chunk);
void	chunk_sort_bside_plus(t_stack *a, int nbr_chunk);
void	check_faster(t_stack *a, t_step *step);
void	check_all_sort(t_stack *a, t_step *step);

//operations
void	swap(t_stack *stack, char c);
void	push(t_stack *a, t_stack *b, char c);
void	rotate(t_stack *stack, char c);
void	reverse_rotate(t_stack *stack, char c);

//checker
int		check_line(t_stack *a);
void	check_tri(t_stack *a);
int		check_swap(char *line, t_stack *a, t_stack *b);
int		check_push(char *line, t_stack *a, t_stack *b);
int		check_rotate(char *line, t_stack *a, t_stack *b);
int		check_reverse_rotate(char *line, t_stack *a, t_stack *b);

#endif