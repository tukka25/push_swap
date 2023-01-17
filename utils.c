/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:49:40 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/17 15:06:58 by abdamoha         ###   ########.fr       */
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
		if (((result > INT_MAX && sign == 1) || (result > 2147483648 && sign == -1)))
		{
			free_strings(tmp);
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	if ((str[i] >= ' ' && str[i] <= '/') || (str[i] >= ':' && str[i] <= 127))
	{
		free_strings(tmp);
		write(2, "Error\n", 6);
		exit(0);
	}
	return (result * sign);
}

// int main()
// {
// 	printf("ft_atoi = %ld\n", ps_atoi("4e", NULL));
// 	printf("atoi    = %d",     atoi("4e"));
// }