/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:17:49 by nneves-a          #+#    #+#             */
/*   Updated: 2024/12/14 17:54:14 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_node_initialization(t_stack_node **node, int n);

static void	put_node_at_the_end(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = ft_calloc(sizeof(t_stack_node), 1);
	if (!node)
		return ;
	ft_node_initialization(&node, n);
	if (!(*stack))
	{
		node->prev = NULL;
		node->next = NULL;
		*stack = node;
	}
	else
	{
		last_node = find_last_node(stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

static void	ft_node_initialization(t_stack_node **node, int n)
{
	(*node)->cheapest = false;
	(*node)->above_median = false;
	(*node)->index = 0;
	(*node)->push_cost = 0;
	(*node)->nbr = n;
	(*node)->next = NULL;
	(*node)->target_node = NULL;
}

static long	ft_atol(char *s, t_stack_node **a, bool flag, char **av)
{
	int		i;
	int		j;
	long	result;
	long	sign;

	i = 0;
	j = 0;
	result = 0;
	sign = 1;
	if (!s || !*s)
		ft_free_errors(a, flag, av);
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result = result + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

void	init_stack_a(char **av, t_stack_node **a, int flag)
{
	long	n;
	int		i;

	if (flag == 1)
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		if (theres_errors_syntax(av[i]) == true
			|| is_there_errors_in_len(av[i]) == true)
			ft_free_errors(a, flag, av);
		n = ft_atol(av[i], a, flag, av);
		if (n > INT_MAX || n < INT_MIN)
			ft_free_errors(a, flag, av);
		if (is_there_duplicates(a, (int)n) != false)
			ft_free_errors(a, flag, av);
		put_node_at_the_end(a, (int)n);
		i++;
	}
}
