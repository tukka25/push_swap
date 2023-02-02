/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:44:43 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/01 22:47:44 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	more_than_hundred(t_ps **s_a, t_ps **s_b)
{
	t_ps	**tmp;
	t_ps	*t;
	t_ps	**tmp2;

	tmp = s_a;
	tmp2 = s_b;
	t = finding_the_quarter(tmp, 6);
	pushing_to_stack_b(t, tmp, tmp2, 6);
	five_and_more(tmp, tmp2);
	push_back_to_stack_a(tmp2, tmp);
}

int	pivot_number_index(t_ps **s_a, int d)
{
	t_vars	vars;

	vars.i = 1;
	vars.j = 0;
	vars.k = 0;
	vars.tmp = (*s_a);
	vars.tmp3 = (*s_a);
	vars.tmp2 = vars.tmp;
	vars.len = ft_lstsize(vars.tmp);
	vars.n = vars.tmp->content;
	while (vars.len)
	{
		vars.tmp = (*s_a);
		if (vars.i != 1)
		{
			vars.tmp2 = vars.tmp2->next;
			vars.n = vars.tmp2->content;
		}
		vars.k = counter(vars.tmp, vars.n);
		if (vars.k == ft_lstsize(vars.tmp3) / d)
			return (vars.i);
		vars.i++;
		vars.len--;
	}
	return (0);
}

t_ps	*finding_the_quarter(t_ps **tmp, int d)
{
	t_ps	*t;
	int		j;

	j = pivot_number_index(tmp, d);
	t = (*tmp);
	if (j >= ft_lstsize((*tmp)) / 2)
	{
		while (pivot_number_index(tmp, d) != 1)
		{
			rra(tmp);
			j++;
		}
	}
	else
	{
		while ((pivot_number_index(tmp, d) != 1))
		{
			ra(tmp);
			j++;
		}
	}
	t = (*tmp);
	ra(tmp);
	return (t);
}

void	pushing_to_stack_b(t_ps *t, t_ps **tmp, t_ps **tmp2, int d)
{
	while (t->content != (*tmp)->content)
	{
		if (t->content > (*tmp)->content)
			pb(tmp, tmp2);
		else
			ra(tmp);
	}
	while (ft_lstsize((*tmp)) > d && if_sorted(tmp) == 1)
	{
		t = finding_the_quarter(tmp, d);
		while (t->content != (*tmp)->content && ft_lstsize((*tmp)) > d)
		{
			if (t->content > (*tmp)->content && ft_lstsize((*tmp)) > d)
				pb(tmp, tmp2);
			else
				ra(tmp);
		}
	}
}

void	push_back_to_stack_a(t_ps **tmp2, t_ps **tmp)
{
	while (ft_lstsize(*tmp2))
	{
		if (second_biggest_number_index(tmp2) == 1)
			pa(tmp, tmp2);
		while (biggest_number_index(tmp2) != 1)
		{
			if (biggest_number_index(tmp2) <= ft_lstsize((*tmp2)) / 2)
			{
				if (biggest_number_index(tmp2) == 2)
					sb(tmp2);
				else
					rb(tmp2);
			}
			else
				rrb(tmp2);
		}
		pa(tmp, tmp2);
		if ((*tmp)->content > (*tmp)->next->content)
			sa(tmp);
	}
}
