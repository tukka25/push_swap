/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:10:18 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/01 19:47:22 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*x;

	if (size != 0 && count >= SIZE_MAX / size)
		return (NULL);
	x = malloc(count * size);
	if (!x)
		return (NULL);
	ft_bzero (x, (size * count));
	return (x);
}
