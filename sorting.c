/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:04:29 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/30 16:14:17 by abdamoha         ###   ########.fr       */
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
	int		j;

	tmp = s_a;
	tmp2 = s_b;
	j = quarter_number_index(tmp);
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
	while ((*tmp2))
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
	// pa(tmp, tmp2);
	// exit(0);
	// sort_four_and_five(tmp, tmp2, ft_lstsize((*tmp)));
	// while (ft_lstsize((*tmp)) < ft_lstsize())
	// {
	// 	pa(tmp, tmp2);
	// }
	// t = (*tmp);
	// printf("s a  = %d\n", ft_lstsize(t));
	// exit(0);
	// while (t)
	// {
	// 	printf("stack a = %d\n", t->content);
	// 	t = t->next;
	// }
	// exit(0);
	// t = (*tmp2);
	// while (t)
	// {
	// 	printf("stack b = %d\n", t->content);
	// 	t = t->next;
	// }
	// sort_four_and_five(tmp, tmp2, ft_lstsize((*tmp)));
	// t = (*tmp2);
	// while (t)
	// {
	// 	if (t->content > (*tmp)->content)
	// 	{
	// 		pa(tmp, tmp2);
	// 		sa(tmp);
	// 	}
	// 	else
	// 		pa(tmp, tmp2);
	// 	t = t->next;
	// }
	// return ;
	// t = (*tmp2);
	// while (t)
	// {
	// 	if (t->content > (*tmp)->content)
	// 	{
	// 		pa(tmp, tmp2);
	// 		sa(tmp);
	// 	}
	// 	else
	// 		pa(tmp, tmp2);
	// 	t = t->next;
	// }
	return ;
}

// /usr/bin/python3 python_visualizer.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`