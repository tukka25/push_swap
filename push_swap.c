/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:50:41 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/17 14:36:27 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	int		i;
	char	**str;
	t_ps	*lst;

	i = 0;
	// int j = 0;
	str = NULL;
	if (ac > 1)
	{
		str = checker(av);
		while (str[i])
		{
			ps_atoi(str[i], str);
			i++;
		}
		lst = insert_into_list(str);
		while (lst->next)
		{
			printf("lst = %d\n", lst->content);
			lst = lst->next;
		}
		printf("lst = %d\n", lst->content);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	// lst = insert_into_list(av);
	// printf("c = %d", lst->content);
}
