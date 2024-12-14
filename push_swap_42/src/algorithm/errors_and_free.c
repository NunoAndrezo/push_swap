/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:10:43 by nneves-a          #+#    #+#             */
/*   Updated: 2024/12/11 22:12:15 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	is_there_duplicates(t_stack_node **a, int n)
{
	t_stack_node	*temp;

	temp = *a;
	while (temp)
	{
		if (n == temp->nbr)
			return (true);
		temp = temp->next;
	}
	return (false);
}

bool	theres_errors_syntax(char *s)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	if (!*s)
		return (true);
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+')
		{
			if ((s[i] == '+' || s[i] == '-')
				&& (s[i + 1] < '0' || s[i + 1] > '9'))
				return (true);
			else
				i++;
		}
		else
			return (true);
	}
	return (0);
}

bool	is_there_errors_in_len(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	while (s[i])
	{
		i++;
		len++;
	}
	if (len <= 10)
		return (false);
	return (true);
}

void	ft_free_errors(t_stack_node **stack, int flag, char **av)
{
	free_stack(stack, flag, av);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **stack, int flag, char **av)
{
	int				i;
	t_stack_node	*tmp;
	t_stack_node	*current;

	i = -1;
	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
	if (flag == 1)
	{
		while (av[++i])
			free(av[i]);
		free(av);
		av = NULL;
	}
}
