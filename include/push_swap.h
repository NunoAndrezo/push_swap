/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:21:16 by nneves-a          #+#    #+#             */
/*   Updated: 2024/12/11 22:21:26 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Commands
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **a, t_stack_node **b);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
void					rotate_booth(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					reverse_rotate_booth(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);

// Stack initialization
void					init_stack_a(char **av, t_stack_node **a, int flag);
char					**ft_split(char const *s, char c);

// Init nodes a
void					init_nodes_a(t_stack_node **a, t_stack_node **b);
void					move_a_to_b(t_stack_node **a, t_stack_node **b);

// Init nodes b
void					init_nodes_b(t_stack_node **a, t_stack_node **b);
void					move_b_to_a(t_stack_node **b, t_stack_node **a);

// Ordering
bool					is_stack_ordered(t_stack_node **stack);
void					order_w_three(t_stack_node **a);
void					order_stacks(t_stack_node **a, t_stack_node **b);

// Stack Axuiliary
t_stack_node			*get_cheapest(t_stack_node *stack);
void					assign_index(t_stack_node **stack);
void					min_on_top(t_stack_node **a);
void					prep_for_pushing(t_stack_node **stack,
							t_stack_node *node_top, char c);

// Utils
t_stack_node			*ft_find_min(t_stack_node **stack);
t_stack_node			*ft_find_max(t_stack_node **stack);
t_stack_node			*find_last_node(t_stack_node **stack);
unsigned int			stack_len(t_stack_node **a);

// Errors and frees
void					free_stack(t_stack_node **stack, int flag, char **av);
void					ft_free_errors(t_stack_node **stack, int flag,
							char **av);
bool					theres_errors_syntax(char *s);
bool					is_there_duplicates(t_stack_node **a, int n);
bool					is_there_errors_in_len(char *s);

#endif /* PUSH_SWAP_H */
