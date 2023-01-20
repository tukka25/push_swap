/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:19:56 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/20 21:28:07 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_number_index(t_ps **s_a)
{
	t_ps	*tmp;
	t_ps	*tmp2;
	int		i;
	int		j;

	i = 1;
	j = 1;
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
