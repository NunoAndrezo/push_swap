/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:13:38 by nneves-a          #+#    #+#             */
/*   Updated: 2024/12/11 22:13:39 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	is_stack_ordered(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!*stack)
		return (1);
	temp = *stack;
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
			return (false);
		temp = temp->next;
	}
	return (true);
}

void	order_w_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = ft_find_max(a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	order_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(a);
	if (len_a-- >= 4 && is_stack_ordered(a) == false)
		pb(a, b);
	if (len_a-- >= 4 && !is_stack_ordered(a))
		pb(a, b);
	while (len_a-- >= 4 && !is_stack_ordered(a))
	{
		init_nodes_a(a, b);
		move_a_to_b(a, b);
	}
	order_w_three(a);
	while (*b)
	{
		init_nodes_b(a, b);
		move_b_to_a(a, b);
	}
	assign_index(a);
	min_on_top(a);
}
