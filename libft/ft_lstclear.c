/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:22:36 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/30 21:43:32 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_ps **lst)
{
	t_ps	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (tmp->next != NULL)
		ft_lstclear(&tmp->next);
	ft_lstdelone(tmp);
	*lst = NULL;
}
