/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:04:29 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/01 22:44:27 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_ps **s_a)
{
	t_vars	v;

	v.t = s_a;
	v.first = (*v.t)->content;
	v.second = (*v.t)->next->content;
	v.third = (*v.t)->next->next->content;
	if (v.first > v.second && v.second < v.third && v.first < v.third)
		sa(v.t);
	else if (v.first > v.second && v.second > v.third)
	{
		sa(v.t);
		rra(v.t);
	}
	else if (v.first > v.second && v.second < v.third && v.first > v.third)
	{
		rra(v.t);
		rra(v.t);
	}
	else if (v.first < v.second && v.second > v.third && v.third > v.first)
	{
		rra(v.t);
		sa(v.t);
	}
	else if (v.first < v.second && v.second > v.third && v.third < v.first)
		rra(v.t);
}

void	sort_four_and_five(t_ps **s_a, t_ps **s_b, int i)
{
	t_ps	**tmp;
	t_ps	**tmp2;
	int		index;

	tmp = s_a;
	tmp2 = s_b;
	index = smallest_number_index(tmp);
	if (index < 3 && ft_lstsize((*tmp)) == 3)
		three_numbers_loop(tmp, tmp2, 3);
	else if (i == 5)
	{
		while (smallest_number_check(tmp) == 1)
			rra(tmp);
		pb(tmp, tmp2);
		while (smallest_number_check(tmp) == 1)
			rra(tmp);
		pb(tmp, tmp2);
		sort_three_numbers(tmp);
		pa(tmp, tmp2);
		pa(tmp, tmp2);
	}
	else
		three_numbers_loop(tmp, tmp2, 0);
}

void	five_and_more(t_ps **s_a, t_ps **s_b)
{
	t_ps	**tmp;
	t_ps	*t;
	t_ps	**tmp2;

	tmp = s_a;
	tmp2 = s_b;
	t = finding_the_middle(tmp);
	pushing_to_stack_b(t, tmp, tmp2, 4);
	sort_four_and_five(tmp, tmp2, ft_lstsize((*tmp)));
	push_back_to_stack_a(tmp2, tmp);
}

int	biggest_number_index(t_ps **s_a)
{
	t_vars	vars;

	vars.i = 1;
	vars.tmp = (*s_a);
	vars.tmp3 = (*s_a);
	vars.tmp2 = vars.tmp;
	vars.len = ft_lstsize(vars.tmp3);
	vars.n = (*s_a)->content;
	while (vars.len)
	{
		vars.tmp = vars.tmp3;
		vars.j = 0;
		vars.k = 0;
		if (vars.i != 1)
		{
			vars.tmp2 = vars.tmp2->next;
			vars.n = vars.tmp2->content;
		}
		vars.k = counter(vars.tmp, vars.n);
		if (vars.k == ft_lstsize((vars.tmp3)) - 1)
			return (vars.i);
		vars.i++;
		vars.len--;
	}
	return (0);
}
