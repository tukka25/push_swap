/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:19:10 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/01 21:19:17 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps **s_a)
{
	t_ps	*tmp;
	t_ps	*tmp2;
	t_ps	*tmp3;

	tmp = (*s_a)->next;
	tmp2 = (*s_a);
	(*s_a) = (*s_a)->next;
	ft_lstadd_back(&tmp, tmp2);
	tmp3 = tmp;
	while (tmp3->content != tmp2->content)
	{
		tmp3 = tmp3->next;
	}
	tmp3->next = NULL;
	s_a = &tmp;
	write(1, "ra\n", 3);
}

void	rra(t_ps **s_a)
{
	t_ps	*tmp;
	t_ps	*tmp2;
	t_ps	*tmp3;
	t_ps	*pre;

	tmp = (*s_a);
	tmp2 = (*s_a);
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	ft_lstadd_front(&tmp, tmp2->next);
	tmp3 = tmp;
	while (tmp3->content != tmp2->content)
	{
		pre = tmp3;
		tmp3 = tmp3->next;
	}
	pre->next->next = NULL;
	(*s_a) = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_ps **s_b)
{
	t_ps	*tmp;
	t_ps	*tmp2;
	t_ps	*pre;
	t_ps	*tmp3;

	tmp = (*s_b);
	tmp2 = (*s_b);
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	ft_lstadd_front(&tmp, tmp2->next);
	tmp3 = tmp;
	while (tmp3->content != tmp2->content)
	{
		pre = tmp3;
		tmp3 = tmp3->next;
	}
	pre->next->next = NULL;
	(*s_b) = tmp;
	write (1, "rrb\n", 4);
}

void	free_parsing(char *str, char *a)
{
	free(str);
	free(a);
	write(2, "Error\n", 6);
	exit(0);
}

void	three_numbers_loop(t_ps	**tmp, t_ps	**tmp2, int index)
{
	if (index == 3)
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
	else
	{
		while (smallest_number_check(tmp) == 1 && tmp)
			rra(tmp);
		pb(tmp, tmp2);
		sort_three_numbers(tmp);
		pa(tmp, tmp2);
	}
}
