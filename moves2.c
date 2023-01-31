/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:19:10 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/30 21:07:37 by abdamoha         ###   ########.fr       */
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
	// free(tmp2);
	tmp3 = tmp;
	// printf("tmp = %d\n", tmp3->content);
	while (tmp3->content != tmp2->content)
	{
		tmp3 = tmp3->next;
	}
	// printf("p = %d\n", pre->content);
	tmp3->next = NULL;
	// free(tmp2);
	s_a = &tmp;
	// free(tmp2);
	write(1, "ra\n", 3);
	// printf("in = %d\n", (*s_a)->next->content);
}

void	rra(t_ps **s_a)
{
	t_ps	*tmp;
	t_ps	*tmp2;
	t_ps	*tmp3;
	// t_ps	*new;
	t_ps	*pre;

	tmp = (*s_a);
	tmp2 = (*s_a);
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	// new = ft_lstnew(tmp2->content);
	ft_lstadd_front(&tmp, tmp2->next);
	// free(new);
	tmp3 = tmp;
	// printf("tmp31 = %d\n", tmp2->content);
	while (tmp3->content != tmp2->content)
	{
		pre = tmp3;
		tmp3 = tmp3->next;
		// printf("tmp3 = %d", tmp3->content);
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

void	ss(t_ps **s_a, t_ps **s_b)
{
	sa((s_a));
	sb((s_b));
	write (1, "ss\n", 3);
}

void	rr(t_ps **s_a, t_ps **s_b)
{
	ra((s_a));
	rb((s_b));
	write (1, "rr\n", 3);
}
