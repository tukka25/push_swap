/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:14:39 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/30 23:29:46 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ps	*ft_lstnew(int content)
{
	t_ps	*new;

	new = NULL;
	new = malloc(sizeof(t_ps));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
