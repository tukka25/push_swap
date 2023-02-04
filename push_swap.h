/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:51:11 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/02 18:15:18 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_vars
{
	t_ps	*tmp;
	t_ps	*tmp2;
	t_ps	*tmp3;
	t_ps	**t;
	int		i;
	int		k;
	int		len;
	int		n;
	int		j;
	int		first;
	int		second;
	int		third;
}	t_vars;

typedef struct s_stack
{
	t_ps	*stack_a;
	t_ps	*stack_b;
}	t_stack;

void		par(char *s);
void		insert_into_list(char **str, t_ps **s_a);
char		**checker(char *av[]);
int			ac_count(char *av[]);
void		free_strings(char **str);
long		ps_atoi(const char *str, char **tmp);
void		double_checker(t_ps **lst);
void		sa(t_ps **lst);
void		sb(t_ps **s_b);
void		ss(t_ps **s_a, t_ps **s_b);
void		pa(t_ps **s_a, t_ps **s_b);
void		pb(t_ps **s_a, t_ps **s_b);
void		ra(t_ps **s_a);
void		rb(t_ps **s_b);
void		rr(t_ps **s_a, t_ps **s_b);
void		rra(t_ps **s_a);
void		rrb(t_ps **s_b);
void		free_list(t_ps **lst);
int			if_sorted(t_ps **s_a);
void		sort_three_numbers(t_ps **s_a);
void		sort_four_and_five(t_ps **s_a, t_ps **s_b, int i);
int			smallest_number_index(t_ps **s_a);
int			smallest_number_check(t_ps **s_a);
void		five_and_more(t_ps **s_a, t_ps **s_b);
int			middle_number_index(t_ps **s_a);
t_ps		*finding_the_middle(t_ps **tmp);
int			second_biggest_number_index(t_ps **s_a);
int			biggest_number_index(t_ps **s_a);
int			pivot_number_index(t_ps **s_a, int d);
void		more_than_hundred(t_ps **s_a, t_ps **s_b);
t_ps		*finding_the_quarter(t_ps **tmp, int d);
void		pushing_to_stack_b(t_ps *t, t_ps **tmp, t_ps **tmp2, int d);
void		push_back_to_stack_a(t_ps **tmp2, t_ps **tmp);
int			counter(t_ps *tmp, int n);
void		free_and_exit(char **tmp);
void		free_parsing(char *str, char *a);
void		three_numbers_loop(t_ps	**tmp, t_ps	**tmp2, int index);
void		parsing_and_insert(char **str, char *av[], int i, t_ps **s_a);
void		sorting_main(char *av[], t_ps **s_a, t_ps **s_b);
void		num_check(char **a);
void		check_if_empty(char **str, char **a);
void		five_numbers(t_ps **tmp, t_ps **tmp2);
#endif