// while (i > 5)
// 	{
// 		while (smallest_number_check(tmp) == 1 && i > 5)
// 		{
// 			if (smallest_number_index(tmp) <= ft_lstsize((*tmp)) / 2)
// 			{
// 				// if (smallest_number_index(&(*tmp)->next) == smallest_number_index(tmp) + 1)
// 				// 	sa(tmp);
// 				// else
// 					ra(tmp);
// 			}
// 			else
// 			{
// 				if (if_sorted(tmp) == 0)
// 				{
// 					while ((*tmp2))
// 					{
// 						pa(tmp, tmp2);
// 						(*tmp2) = (*tmp2)->next;
// 					}
// 					return ;
// 				}
// 				rra(tmp);
// 			}
// 		}
// 		pb(tmp, tmp2);
// 		// printf("tmp2 = %d\n", (*tmp2)->content);
// 		// printf("t1 = %d\n", ft_lstsize((*tmp)));
// 		i--;
// 	}
// 	sort_four_and_five(tmp, tmp2, i);
// 	t = (*tmp2);
// 	// int	j = 0;
// 	while (t)
// 	{
// 		// printf("b = %d\n", (*tmp2)->content);
// 		pa(tmp, tmp2);
// 		// t = tmp2;
// 		// if ((*t))
// 		t = t->next;
// 		// else
// 		// 	break;
// 		// j++;
// 	}
// 	return ;
// }


//////////////////////////////////////////////////////////////////////////////////////

// j = middle_number_index(tmp);
// 	// printf("j = %d\n", j);
// 	// exit(0);
// 	t = (*tmp);
// 	while (j - 1 < ft_lstsize((*tmp)))
// 	{
// 		rra(tmp);
// 		// printf("tmp = %d\n", (*tmp)->content);
// 		j++;
// 	}
// 	t = (*tmp);
// 	ra(tmp);
// 	while (t->content != (*tmp)->content)
// 	{
// 		if (t->content > (*tmp)->content)
// 		{
// 			pb(tmp, tmp2);
// 		}
// 		else
// 		{
// 			ra(tmp);
// 		}
// 	}
// 	while (ft_lstsize((*tmp)) > 5)
// 	{
// 		t = finding_the_middle(tmp);
// 		printf("t = %d\n", t->content);
// 		while (t->content != (*tmp)->content)
// 		{
// 			if (t->content > (*tmp)->content)
// 			{
// 				pb(tmp, tmp2);
// 			}
// 			else
// 			{
// 				ra(tmp);
// 			}
// 		}
// 	}
// 	// exit(0);
// 	sort_four_and_five(tmp, tmp2, ft_lstsize((*tmp)));
// 	while (ft_lstsize((*tmp)) < 50)
// 	{
// 		pa(tmp, tmp2);
// 	}
// 	t = (*tmp);
// 	// printf("s a  = %d\n", ft_lstsize(t));
// 	// exit(0);
// 	while (t)
// 	{
// 		printf("stack a = %d\n", t->content);
// 		t = t->next;
// 	}
// 	exit(0);
// 	t = (*tmp2);
// 	while (t)
// 	{
// 		printf("stack b = %d\n", t->content);
// 		t = t->next;
// 	}
// 	exit(0);
// 	// sort_four_and_five(tmp, tmp2, ft_lstsize((*tmp)));
// 	// t = (*tmp2);
// 	// while (t)
// 	// {
// 	// 	if (t->content > (*tmp)->content)
// 	// 	{
// 	// 		pa(tmp, tmp2);
// 	// 		sa(tmp);
// 	// 	}
// 	// 	else
// 	// 		pa(tmp, tmp2);
// 	// 	t = t->next;
// 	// }
// 	return ;