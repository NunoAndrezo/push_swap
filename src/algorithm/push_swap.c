/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:09:22 by nneves-a          #+#    #+#             */
/*   Updated: 2024/12/11 22:17:35 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_help(t_stack_node **a, t_stack_node **b);

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				flag;

	a = NULL;
	b = NULL;
	flag = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		flag = 1;
	}
	init_stack_a(av, &a, flag);
	ft_help(&a, &b);
	free_stack(&a, flag, av);
	return (0);
}

static void	ft_help(t_stack_node **a, t_stack_node **b)
{
	if (is_stack_ordered(a) == false)
	{
		if (stack_len(a) == 2)
			sa(a);
		else if (stack_len(a) == 3)
			order_w_three(a);
		else
			order_stacks(a, b);
	}
}
