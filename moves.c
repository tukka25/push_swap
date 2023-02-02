/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:16:20 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/01 19:41:38 by abdamoha         ###   ########.fr       */
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
	t_ps		**tmp2;

	tmp = (*s_a);
	tmp2 = s_b;
	(*s_a) = (*s_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(tmp2, tmp);
	write (1, "pb\n", 3);
	s_b = tmp2;
}

void	pa(t_ps **s_a, t_ps **s_b)
{
	t_ps	*tmp;

	tmp = (*s_b);
	(*s_b) = (*s_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(s_a, tmp);
	write (1, "pa\n", 3);
}

void	rb(t_ps **s_b)
{
	t_ps	*tmp2;

	tmp2 = (*s_b);
	(*s_b) = (*s_b)->next;
	tmp2->next = NULL;
	ft_lstadd_back(s_b, tmp2);
	write (1, "rb\n", 3);
}
