/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_auxil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:19:19 by nneves-a          #+#    #+#             */
/*   Updated: 2024/12/11 22:13:16 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	t_stack_node	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->cheapest)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	assign_index(t_stack_node **stack)
{
	int				i;
	int				median;
	t_stack_node	*temp;

	i = 0;
	temp = *stack;
	median = stack_len(stack) / 2;
	while (temp)
	{
		temp->index = i;
		if (i > median)
			temp->above_median = false;
		else
			temp->above_median = true;
		temp = temp->next;
		i++;
	}
}

void	min_on_top(t_stack_node **a)
{
	while (*a != ft_find_min(a))
	{
		if (ft_find_min(a))
			ra(a);
		else
			rra(a);
	}
}

void	prep_for_pushing(t_stack_node **stack, t_stack_node *node_top, char c)
{
	while (*stack != node_top)
	{
		if (c == 'a')
		{
			if (node_top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (node_top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
