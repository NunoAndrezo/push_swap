/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:57:33 by nneves-a          #+#    #+#             */
/*   Updated: 2024/12/11 22:12:59 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	b_targeting_a(t_stack_node **a, t_stack_node **b)
{
	long			best_match;
	t_stack_node	*target_node;
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;

	temp_b = *b;
	while (temp_b)
	{
		best_match = LONG_MAX;
		temp_a = *a;
		while (temp_a)
		{
			if ((temp_a->nbr > temp_b->nbr) && (temp_a->nbr < best_match))
			{
				best_match = temp_a->nbr;
				target_node = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (best_match != LONG_MAX)
			temp_b->target_node = target_node;
		else
			temp_b->target_node = ft_find_min(a);
		temp_b = temp_b->next;
	}
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_pushing(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	init_nodes_b(t_stack_node **a, t_stack_node **b)
// Define a function that prepares the nodes for pushing `b` to `a`
{
	assign_index(a);
	assign_index(b);
	b_targeting_a(a, b);
}
