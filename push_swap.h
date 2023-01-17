/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:51:11 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/16 22:49:24 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "./libft/libft.h"

// typedef struct t_ps
// {
// 	int				content;
// 	struct s_list	*next;
// }	t_ps;

typedef struct s_stack
{
	t_ps	*stack_a;
	t_ps	*stack_b;
}	t_stack;

void		par(char *s);
t_ps		*insert_into_list(char *av[]);
int			ac_len(char *av[]);
char		**checker(char *av[]);
int			ac_count(char *av[]);
void		free_strings(char **str);
long		ps_atoi(const char *str, char **tmp);
#endif