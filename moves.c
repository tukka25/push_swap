/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:16:20 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/20 20:14:32 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps **lst)
{
	t_ps	*tmp;
	int		swaper;

	tmp = (*lst);
	tmp = tmp->next;
	swaper = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = swaper;
	write(1, "sa\n", 3);
}

void	sb(t_ps **lst)
{
	t_ps	*tmp;
	int		swaper;

	tmp = (*lst);
	tmp = tmp->next;
	swaper = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = swaper;
	write (1, "sb\n", 3);
}

void	pb(t_ps **s_a, t_ps **s_b)
{
	t_ps		*tmp;

	tmp = (*s_a);
	(*s_a) = (*s_a)->next;
	ft_lstadd_front((s_b), ft_lstnew(tmp->content));
	write (1, "pb\n", 3);
	free(tmp);
}

void	pa(t_ps **s_a, t_ps **s_b)
{
	t_ps	*tmp;

	tmp = (*s_b);
	ft_lstadd_front((s_a), ft_lstnew(tmp->content));
	write (1, "pa\n", 3);
	(*s_b) = (*s_b)->next;
}

void	rb(t_ps **s_b)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	tmp = (*s_b)->next;
	tmp2 = (*s_b);
	(*s_b) = (*s_b)->next;
	ft_lstadd_back(&tmp, ft_lstnew(tmp2->content));
	s_b = &tmp;
	write (1, "rb\n", 3);
}
