/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:58:31 by nneves-a          #+#    #+#             */
/*   Updated: 2024/12/11 22:18:25 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*node_to_be_pushed;

	if (!*src)
		return ;
	node_to_be_pushed = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_be_pushed->prev = NULL;
	if (*dst)
	{
		node_to_be_pushed->next = *dst;
		node_to_be_pushed->next->prev = node_to_be_pushed;
		*dst = node_to_be_pushed;
	}
	else
	{
		(*dst) = node_to_be_pushed;
		node_to_be_pushed->next = NULL;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
