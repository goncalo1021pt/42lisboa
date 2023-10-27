/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:16:51 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/27 17:08:53 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct s_node
{
	int				value;
	int				nbr;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_next_elements
{
	int	nbr;
	int	cost;
}	t_next_elements;

//lists
t_node	*ft_dbl_new(int content);
void	ft_dbl_add_front(t_stack *stack, t_node *new);
void	ft_dbl_add_back(t_stack *stack, t_node *new);
t_node	*ft_dbl_rem_front(t_stack *stack);
t_node	*ft_dbl_rem_back(t_stack *stack);

//lists2
void	ft_dbl_clear(t_stack *stack);
int		ft_dbl_not_equal(t_stack *stack, int content);
t_node	*find_node(t_stack stack, int value);
t_bool	is_sorted(t_node *low);

//swap
void	ft_swap_01(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_rev_rotate(t_stack *stack);
void	ft_push(t_stack *src, t_stack *dest);
void	ft_dbl_print(t_stack *stack);

//costs
int		head_cost(t_stack *stack, t_node *pivot);
int		tail_cost(t_stack *stack, t_node *pivot);
int		medium(t_node *low, t_node *high);
t_node	*find_last_not_sorted(t_stack *stack);

int		save_stack(char **input, t_stack *stack_a);

void	quick_sort(t_stack *stack_a, t_stack *stack_b);

#endif