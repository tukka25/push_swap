/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:19:56 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/29 14:53:35 by abdamoha         ###   ########.fr       */
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
	// tmp2 = tmp->next;
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

int	middle_number_index(t_ps **s_a)
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
			{
				k++;
			}
			tmp = tmp->next;
		}
		if (!tmp && k == ft_lstsize((*s_a)) / 2)
		{
			return (i);
		}
		i++;
		len--;
	}
	return (0);
}

t_ps	*finding_the_middle(t_ps **tmp)
{
	t_ps	*t;
	int		j;

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
	return (t);
}

int	second_biggest_number_index(t_ps **s_a)
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
		if (!tmp && k == ft_lstsize(tmp3) - 2)
			return (i);
		i++;
		len--;
	}
	return (0);
}

int	biggest_number_index(t_ps **s_a)
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
	if (!(*s_a))
		return (1);
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
		if (!tmp && k == ft_lstsize((tmp3)) - 1)
			return (i);
		i++;
		len--;
	}
	return (0);
}
