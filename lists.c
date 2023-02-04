/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:11:55 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/02 21:09:06 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_into_list(char **str, t_ps **s_a)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = ps_atoi(str[i], str);
		ft_lstadd_back(s_a, ft_lstnew(j));
		i++;
	}
	free_strings(str);
}

int	ac_count(char *av[])
{
	int		i;
	int		j;
	int		k;
	char	**s;

	i = 1;
	k = 0;
	j = 0;
	s = NULL;
	while (av[i] != NULL)
	{
		if (ft_strchr(av[i], ' ') != NULL)
		{
			s = ft_split(av[i], ' ');
			while (s[j++] != NULL)
				k++;
			free_strings(s);
		}
		else
			k++;
		i++;
		j = 0;
	}
	return (k);
}

char	**checker(char *av[])
{
	int		i;
	int		j;
	int		k;
	char	**a;
	char	**str;

	i = 1;
	j = 0;
	k = 0;
	str = NULL;
	a = ft_calloc((ac_count(av) + 1), sizeof(char *));
	while (av[i] != NULL)
	{
		str = ft_split(av[i], ' ');
		check_if_empty(str, a);
		while (str[j] != NULL)
			a[k++] = ft_strdup(str[j++]);
		if (str)
			free_strings(str);
		i++;
		j = 0;
	}
	a[k] = NULL;
	num_check(a);
	return (a);
}

void	free_strings(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
