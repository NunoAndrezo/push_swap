/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:18:01 by nneves-a          #+#    #+#             */
/*   Updated: 2024/12/11 22:18:11 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

unsigned int	stack_len(t_stack_node **a)
{
	unsigned int	i;
	t_stack_node	*temp;

	i = 0;
	if (!*a || !a)
		return (0);
	temp = *a;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_stack_node	*find_last_node(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!(*stack))
		return (NULL);
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_stack_node	*ft_find_max(t_stack_node **stack)
{
	t_stack_node	*biggest_node;
	t_stack_node	*temp;

	if (!(*stack))
		return (NULL);
	biggest_node = *stack;
	temp = *stack;
	while (temp)
	{
		if (biggest_node->nbr < temp->nbr)
			biggest_node = temp;
		temp = temp->next;
	}
	return (biggest_node);
}

t_stack_node	*ft_find_min(t_stack_node **stack)
{
	t_stack_node	*smallest_node;
	t_stack_node	*temp;

	if (!*stack)
		return (NULL);
	temp = *stack;
	smallest_node = *stack;
	while (temp)
	{
		if (smallest_node->nbr > temp->nbr)
			smallest_node = temp;
		temp = temp->next;
	}
	return (smallest_node);
}
