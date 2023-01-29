/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:44:43 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/29 15:45:15 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	more_than_hundred(t_ps **s_a, t_ps **s_b)
{
	t_ps	**tmp;
	t_ps	*t;
	t_ps	**tmp2;
	int		i;
	int		j;

	tmp = s_a;
	tmp2 = s_b;
	i = smallest_number_index(tmp);
	j = middle_number_index(tmp);
	t = (*tmp);
	if (j >= ft_lstsize((*tmp)) / 2)
	{
		while (middle_number_index(tmp) != 1)
		{
			rra(tmp);
			j++;
		}
	}
	else
	{
		while ((middle_number_index(tmp) != 1))
		{
			ra(tmp);
			j++;
		}
	}
	t = (*tmp);
	ra(tmp);
	while (t->content != (*tmp)->content)
	{
		if (t->content > (*tmp)->content)
			pb(tmp, tmp2);
		else
			ra(tmp);
	}
	while (ft_lstsize((*tmp)) > 2 && if_sorted(tmp) == 1)
	{
		t = finding_the_middle(tmp);
		while (t->content != (*tmp)->content && ft_lstsize((*tmp)) > 2)
		{
			if (t->content > (*tmp)->content && ft_lstsize((*tmp)) > 2)
				pb(tmp, tmp2);
			else
				ra(tmp);
		}
	}
	if ((*tmp)->content > (*tmp)->next->content)
		sa(tmp);
	// exit(0);
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
			{
				rrb(tmp2);
			}
		}
		pa(tmp, tmp2);
		if ((*tmp)->content > (*tmp)->next->content)
			sa(tmp);
	}