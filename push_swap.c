/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:50:41 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/02 16:10:26 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	int		i;
	t_stack	s;	
	char	**str;

	i = 0;
	str = NULL;
	s.stack_a = NULL;
	s.stack_b = NULL;
	if (ac > 1)
	{
		parsing_and_insert(str, av, i, &s.stack_a);
		sorting_main(av, &s.stack_a, &s.stack_b);
		free_list(&s.stack_a);
	}
	else
		exit(0);
}

void	parsing_and_insert(char **str, char *av[], int i, t_ps **s_a)
{
	str = checker(av);
	while (str[i])
	{
		ps_atoi(str[i], str);
		i++;
	}
	insert_into_list(str, s_a);
	double_checker(s_a);
	if (if_sorted(s_a) == 0)
	{
		free_list(s_a);
		exit(0);
	}
}

void	sorting_main(char *av[], t_ps **s_a, t_ps **s_b)
{
	if (ac_count(av) >= 2 && ac_count(av) <= 3)
	{
		if (ac_count(av) == 3)
			sort_three_numbers(s_a);
		else
			if ((*s_a)->content > (*s_a)->next->content)
				sa(s_a);
	}
	else if (ac_count(av) > 3)
	{
		if (ac_count(av) > 3 && ac_count(av) <= 5)
			sort_four_and_five(s_a, s_b, ac_count(av));
		else if (ac_count(av) <= 100)
			five_and_more(s_a, s_b);
		else
			more_than_hundred(s_a, s_b);
	}
}

void	num_check(char **a)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (a[k] != NULL)
	{
		j = 0;
		while (a[k][j] != '\0')
		{
			if (!(a[k][j] >= '0' && a[k][j] <= '9'))
				free_and_exit(a);
			j++;
		}
		k++;
	}
}

void	check_if_empty(char **str, char **a)
{
	if (!*str)
	{
		free(str);
		free_strings(a);
		write(2, "Error\n", 6);
		exit(0);
	}
}
