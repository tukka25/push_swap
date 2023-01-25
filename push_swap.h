/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:51:11 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/24 21:41:39 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "./libft/libft.h"

// typedef struct t_ps
// {
// 	int				content;
// 	struct s_list	*next;
// }	t_ps;

typedef struct s_stack
{
	t_ps	*stack_a;
	t_ps	*stack_b;
}	t_stack;

void		par(char *s);
t_ps		*insert_into_list(char *av[]);
int			ac_len(char *av[]);
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
void		rrr(t_ps **s_a, t_ps **s_b);
void		free_list(t_ps *lst);
int			if_sorted(t_ps **s_a);
void		sort_three_numbers(t_ps **s_a);
void		sort_four_and_five(t_ps **s_a, t_ps **s_b, int i);
int			smallest_number_index(t_ps **s_a);
int			smallest_number_check(t_ps **s_a);
void		five_and_more(t_ps **s_a, t_ps **s_b);
int			second_smallest_number_index(t_ps **s_a);
#endif