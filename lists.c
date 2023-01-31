/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:11:55 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/31 14:39:37 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_into_list(char **str, t_ps **s_a)
{
	int		i;
	int		j;
	// t_ps	*new;

	i = 0;
	// k = 0; 
	while (str[i])
	{
		// printf("i = %d", i);
		j = ps_atoi(str[i], str);
		// new = ft_lstnew(j);
		ft_lstadd_back(s_a, ft_lstnew(j));
		// if (new)
		// 	free(new);
		// free(t);
		i++;
		// k++;
	}
	// ft_lstclear(s_a);
	free_strings(str);
	// exit(0);
}

int	ac_len(char *av[])
{
	int		i;

	i = 0;
	if (!av)
		return (0);
	while (av[i])
	{
		i++;
	}
	return (i);
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
			while (s[j] != NULL)
			{
				j++;
				k++;
			}
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
	a = malloc((ac_count(av)+ 1) * sizeof(char *));
	while (av[i] != NULL)
	{
		str = ft_split(av[i], ' ');
		if (!*str)
		{
			free(str);
			free(a);
			write(2, "Error\n", 6);
			exit(0);
		}
		while (str[j] != NULL)
		{
			a[k] = ft_strdup(str[j]);
			k++;
			j++;
		}
		if (str)
			free_strings(str);
		i++;
		j = 0;
	}
	// free_strings(str);
	// printf("k = %d", k);
	a[k] = NULL;
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
