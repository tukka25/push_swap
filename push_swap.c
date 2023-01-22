/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:50:41 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/22 16:41:37 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	int		i;
	t_stack	s;	
	char	**str;
	t_ps	*lst;

	i = 0;
	str = NULL;
	lst = NULL;
	s.stack_a = NULL;
	s.stack_b = NULL;
	if (ac > 1)
	{
		str = checker(av);
		while (str[i])
		{
			ps_atoi(str[i], str);
			i++;
		}
		s.stack_a = insert_into_list(str);
		double_checker(&s.stack_a);
		if (if_sorted(&s.stack_a) == 0)
		{
			free_list(s.stack_a);
			exit(0);
		}
		if (ac_count(av) == 3)
		{
			if (ac_count(av) == 3)
				sort_three_numbers(&s.stack_a);
			lst = s.stack_a;
			while (lst)
			{
				printf("stack_a  = %d\n", lst->content);
				lst = lst->next;
			}
			if (if_sorted(&s.stack_a) == 0)
				printf("Well Done");
			else
				printf("Not Sorted");
			exit(0);
		}
		else if (ac_count(av) > 3)
		{
			five_and_more(&s.stack_a, &s.stack_b);
			// printf("i = %d\n", ft_lstsize(s.stack_a));
			// exit(0);
			// if (if_sorted(&s.stack_a) == 0)
			// 	printf("Well Done\n");
			// else
			// 	printf("Not Sorted");
			// lst = s.stack_a;
			// while (lst)
			// {
			// 	printf("stack_a before  = %d\n", lst->content);
			// 	lst = lst->next;
			// }
			// printf("s_b = %d", s.stack_b->content);
			// free_list(s.stack_a);
			exit(0);
		}
		
		// printf("stack_a2 = %d", s.stack_a->content);
		// while (s.stack_b)
		// {
		// 	printf("lst = %d\n", s.stack_b->content);
		// 	s.stack_b = s.stack_b->next;
		// }
		// free_list(&s.stack_a);
		// printf("lst = %d\n", s.stack_a->content);
		// printf("lst = %d\n", lst->next->content);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}
