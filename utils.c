/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:49:40 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/02 20:44:40 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ps_atoi(const char *str, char **tmp)
{
	int					sign;
	unsigned long long	result;
	int					i;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		++i;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if (((result > INT_MAX && sign == 1)
				|| (result > 2147483648 && sign == -1)))
			free_and_exit(tmp);
	}
	if ((str[i] >= ' ' && str[i] <= '/') || (str[i] >= ':' && str[i] < 127))
		free_and_exit(tmp);
	return (result * sign);
}

void	double_checker(t_ps **lst)
{
	t_ps	*tmp;
	t_ps	*last;

	tmp = (*lst)->next;
	last = (*lst);
	while (last)
	{
		tmp = last->next;
		while (tmp)
		{
			if (last->content == tmp->content)
			{
				free_list(lst);
				write(2, "Error\n", 6);
				exit(0);
			}
			tmp = tmp->next;
		}
		last = last->next;
	}
}

void	free_list(t_ps **lst)
{
	t_ps	*tmp;

	while ((*lst)->next)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
	}
	free(*lst);
}

void	free_and_exit(char **tmp)
{
	free_strings(tmp);
	write(2, "Error\n", 6);
	exit(0);
}

int	if_sorted(t_ps **s_a)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	tmp = (*s_a);
	tmp2 = tmp->next;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content > tmp2->content)
			{
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
