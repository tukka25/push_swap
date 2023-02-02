/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:19:56 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/01 20:10:43 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_number_index(t_ps **s_a)
{
	t_ps	*tmp;
	t_ps	*tmp2;
	int		i;

	i = 1;
	tmp = (*s_a);
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content < tmp2->content)
				tmp2 = tmp2->next;
			else
				break ;
		}
		if (!tmp2)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	smallest_number_check(t_ps **s_a)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	tmp = (*s_a);
	if (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content > tmp2->content)
			{
				return (1);
			}
			tmp2 = tmp2->next;
		}
	}
	return (0);
}

int	counter(t_ps *tmp, int n)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (tmp)
	{
		if (n <= tmp->content)
			j++;
		else
			k++;
		tmp = tmp->next;
	}
	return (k);
}

t_ps	*finding_the_middle(t_ps **tmp)
{
	t_ps	*t;
	int		j;

	j = pivot_number_index(tmp, 4);
	t = (*tmp);
	if (j >= ft_lstsize((*tmp)) / 2)
	{
		while (pivot_number_index(tmp, 4) != 1)
		{
			rra(tmp);
			j++;
		}
	}
	else
	{
		while ((pivot_number_index(tmp, 4) != 1))
		{
			ra(tmp);
			j++;
		}
	}
	t = (*tmp);
	ra(tmp);
	return (t);
}

int	second_biggest_number_index(t_ps **s_a)
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
		if (vars.k == ft_lstsize(vars.tmp3) - 2)
			return (vars.i);
		vars.i++;
		vars.len--;
	}
	return (0);
}
