/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:58:11 by nneves-a          #+#    #+#             */
/*   Updated: 2024/12/11 22:12:53 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	a_targetting_b(t_stack_node **a, t_stack_node **b)
{
	long			best_match;
	t_stack_node	*target_node;
	t_stack_node	*temp_b;
	t_stack_node	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		best_match = LONG_MIN;
		temp_b = *b;
		while (temp_b)
		{
			if ((temp_b->nbr < temp_a->nbr) && (temp_b->nbr > best_match))
			{
				best_match = temp_b->nbr;
				target_node = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (best_match != LONG_MIN)
			temp_a->target_node = target_node;
		else
			temp_a->target_node = ft_find_max(b);
		temp_a = temp_a->next;
	}
}

static void	cost_analysis_a(t_stack_node **a, t_stack_node **b)
{
	int				stacklen_a;
	int				stacklen_b;
	t_stack_node	*temp;

	stacklen_a = stack_len(a);
	stacklen_b = stack_len(b);
	temp = *a;
	while (temp)
	{
		temp->push_cost = temp->index;
		if (temp->above_median == false)
			temp->push_cost = (stacklen_a - temp->index);
		if (temp->target_node->above_median)
			temp->push_cost += temp->target_node->index;
		else
			temp->push_cost += (stacklen_b - temp->target_node->index);
		temp = temp->next;
	}
}

static void	set_cheapest(t_stack_node **stack)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*temp;
	long			cheapest;

	cheapest_node = *stack;
	if (!(*stack))
		return ;
	cheapest = LONG_MAX;
	temp = *stack;
	while (temp)
	{
		if (cheapest > temp->push_cost)
		{
			cheapest = temp->push_cost;
			cheapest_node = temp;
		}
		temp = temp->next;
	}
	cheapest_node->cheapest = true;
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (!cheapest)
		return ;
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_booth(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		reverse_rotate_booth(a, b, cheapest);
	prep_for_pushing(a, cheapest, 'a');
	prep_for_pushing(b, cheapest->target_node, 'b');
	pb(a, b);
}

void	init_nodes_a(t_stack_node **a, t_stack_node **b)
{
	assign_index(a);
	assign_index(b);
	a_targetting_b(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
