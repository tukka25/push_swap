/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:44:43 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/30 14:40:48 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	more_than_hundred(t_ps **s_a, t_ps **s_b)
{
	t_ps	**tmp;
	t_ps	*t;
	t_ps	**tmp2;
	int		j;

	tmp = s_a;
	tmp2 = s_b;
	j = quarter_number_index(tmp);
	t = (*tmp);
	if (j >= ft_lstsize((*tmp)) / 2)
	{
		while (quarter_number_index(tmp) != 1)
		{
			rra(tmp);
			j++;
		}
	}
	else
	{
		while ((quarter_number_index(tmp) != 1))
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
	while (ft_lstsize((*tmp)) > 8 && if_sorted(tmp) == 1)
	{
		t = finding_the_quarter(tmp);
		while (t->content != (*tmp)->content && ft_lstsize((*tmp)) > 8)
		{
			if (t->content > (*tmp)->content && ft_lstsize((*tmp)) > 8)
				pb(tmp, tmp2);
			else
				ra(tmp);
		}
	}
	five_and_more(tmp, tmp2);
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
}

int	quarter_number_index(t_ps **s_a)
{
	t_ps	*tmp;
	t_ps	*tmp2;
	t_ps	*tmp3;
	int		i;
	int		k = 0;
	int		len;
	int		n = 0;
	int		j = 0;

	i = 1;
	tmp = (*s_a);
	tmp3 = (*s_a);
	tmp2 = tmp;
	len = ft_lstsize(tmp3);
	n = (*s_a)->content;
	while (len)
	{
		tmp = tmp3;
		j = 0;
		k = 0;
		if (i != 1)
		{
			tmp2 = tmp2->next;
			n = tmp2->content;
		}
		while (tmp)
		{
			if (n <= tmp->content)
				j++;
			else
				k++;
			tmp = tmp->next;
		}
		if (!tmp && k == ft_lstsize((*s_a)) / 8)
			return (i);
		i++;
		len--;
	}
	return (0);
}

t_ps	*finding_the_quarter(t_ps **tmp)
{
	t_ps	*t;
	int		j;

	j = quarter_number_index(tmp);
	t = (*tmp);
	if (j >= ft_lstsize((*tmp)) / 2)
	{
		while (quarter_number_index(tmp) != 1)
		{
			rra(tmp);
			j++;
		}
	}
	else
	{
		while ((quarter_number_index(tmp) != 1))
		{
			ra(tmp);
			j++;
		}
	}
	t = (*tmp);
	ra(tmp);
	return (t);
}
