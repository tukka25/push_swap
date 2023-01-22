/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:04:29 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/22 17:49:59 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_ps **s_a)
{
	t_ps	**tmp;

	tmp = s_a;
	if (tmp)
	{
		if ((*tmp)->content > (*tmp)->next->content && (*tmp)->next->content < (*tmp)->next->next->content && (*tmp)->content < (*tmp)->next->next->content)
		{
			//2 1 3
			sa(tmp);
			// break ;
		}
		else if ((*tmp)->content > (*tmp)->next->content && (*tmp)->next->content > (*tmp)->next->next->content)
		{
			// 3 2 1
			sa(tmp);
			rra(tmp);
			// break ;
		}
		else if ((*tmp)->content > (*tmp)->next->content && (*tmp)->next->content < (*tmp)->next->next->content && (*tmp)->content > (*tmp)->next->next->content)
		{
			rra(tmp);
			rra(tmp);
			// break ;
		}
		else if ((*tmp)->content < (*tmp)->next->content && (*tmp)->next->content > (*tmp)->next->next->content && (*tmp)->next->next->content > (*tmp)->content)
		{
			rra(tmp);
			sa(tmp);
			// break ;
		}
		else if ((*tmp)->content < (*tmp)->next->content && (*tmp)->next->content > (*tmp)->next->next->content && (*tmp)->next->next->content < (*tmp)->content)
		{
			rra(tmp);
			// break ;
		}
	}
}

void	sort_four_and_five(t_ps **s_a, t_ps **s_b, int i)
{
	t_ps	**tmp;
	t_ps	**tmp2;
	int		index;

	tmp = s_a;
	tmp2 = s_b;
	index = smallest_number_index(tmp);
	// printf("i = %d", ft_lstsize((*s_a)));
	// exit(0);
	if (index < 3 && ft_lstsize((*tmp)) == 3)
	{
		if ((*tmp)->content < (*tmp)->next->content)
			pb(tmp, tmp2);
		else
		{
			sa(tmp);
			pb(tmp, tmp2);
		}
		while (smallest_number_check(tmp) == 1)
			rra(tmp);
		pb(tmp, tmp2);
		sort_three_numbers(tmp);
		pa(tmp, tmp2);
		pa(tmp, tmp2);
	}
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
	{
		while (smallest_number_check(tmp) == 1 && tmp)
			rra(tmp);
		pb(tmp, tmp2);
		sort_three_numbers(tmp);
		pa(tmp, tmp2);
	}
}

void	five_and_more(t_ps **s_a, t_ps **s_b)
{
	t_ps	**tmp;
	t_ps	*t;
	t_ps	**tmp2;
	int		i;

	tmp = s_a;
	tmp2 = s_b;
	i = ft_lstsize((*tmp));
	// printf("i = %d", i);
	// exit(0);
	while (i > 5)
	{
		while (smallest_number_check(tmp) == 1 && i > 5)
		{
			if (smallest_number_index(tmp) <= ft_lstsize((*tmp)) / 2)
			{
				// if (smallest_number_index(&(*tmp)->next) == smallest_number_index(tmp) + 1)
				// 	sa(tmp);
				// else
					ra(tmp);
			}
			else
			{
				if (if_sorted(tmp) == 0)
				{
					while ((*tmp2))
					{
						pa(tmp, tmp2);
						(*tmp2) = (*tmp2)->next;
					}
					return ;
				}
				rra(tmp);
			}
		}
		pb(tmp, tmp2);
		// printf("tmp2 = %d\n", (*tmp2)->content);
		// printf("t1 = %d\n", ft_lstsize((*tmp)));
		i--;
	}
	sort_four_and_five(tmp, tmp2, i);
	t = (*tmp2);
	// int	j = 0;
	while (t)
	{
		// printf("b = %d\n", (*tmp2)->content);
		pa(tmp, tmp2);
		// t = tmp2;
		// if ((*t))
		t = t->next;
		// else
		// 	break;
		// j++;
	}
	return ;
}

// /usr/bin/python3 python_visualizer.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`