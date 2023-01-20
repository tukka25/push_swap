/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:04:29 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/20 20:27:39 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_ps **s_a)
{
	t_ps	**tmp;

	tmp = s_a;
	while (tmp)
	{
		if ((*tmp)->content > (*tmp)->next->content && (*tmp)->next->content < (*tmp)->next->next->content && (*tmp)->content < (*tmp)->next->next->content)
		{
			//2 1 3
			sa(tmp);
			break ;
		}
		else if ((*tmp)->content > (*tmp)->next->content && (*tmp)->next->content > (*tmp)->next->next->content)
		{
			// 3 2 1
			sa(tmp);
			rra(tmp);
			break ;
		}
		else if ((*tmp)->content > (*tmp)->next->content && (*tmp)->next->content < (*tmp)->next->next->content && (*tmp)->content > (*tmp)->next->next->content)
		{
			rra(tmp);
			rra(tmp);
			break ;
		}
		else if ((*tmp)->content < (*tmp)->next->content && (*tmp)->next->content > (*tmp)->next->next->content && (*tmp)->next->content > (*tmp)->content)
		{
			rra(tmp);
			sa(tmp);
			break ;
		}
	}
}

void	sort_four_and_five(t_ps **s_a, t_ps **s_b)
{
	t_ps	**tmp;
	t_ps	**tmp2;
	int		index;

	tmp = s_a;
	tmp2 = s_b;
	index = smallest_number_index(tmp);
	if (index < 3)
	{
		if ((*tmp)->content < (*tmp)->next->content)
			pb(tmp, tmp2);
		else
		{
			sa(tmp);
			pb(tmp, tmp2);
		}
		pb(tmp, tmp2);
		sort_three_numbers(tmp);
		pa(tmp, tmp2);
		pa(tmp, tmp2);
		// break ;
	}
}
