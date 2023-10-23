/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:04:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/23 09:23:28 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	medium(t_stack stack, t_node *high)
{
	int	max;
	int	min;

	max = stack.head->value;
	min = stack.head->value;
	while (stack.head != high)
	{
		if (max < stack.head->value)
			max = stack.head->value;
		if (min > stack.head->value)
			min = stack.head->value;
		stack.head = stack.head->next;
	}
	return ((max + min) / 2);
}

void	send_pivot(t_stack *stack_a, t_stack *stack_b, t_node *pivot)
{
	if (head_cost((*stack_a).head, pivot) < tail_cost((*stack_b).tail, pivot))
	{
		while (stack_a->head != pivot)
			ft_rotate(stack_a);
		ft_push(stack_a, stack_b);
	}
	else
	{
		while (stack_a->head != pivot)
			ft_rev_rotate(stack_a);
		ft_push(stack_a, stack_b);
	}
}

void	restore(t_stack *stack_a, t_stack *stack_b, t_node *top)
{
	if (head_cost((*stack_a).head, top) < tail_cost((*stack_b).tail, top))
	{
		while (stack_a->head != top)
			ft_rotate(stack_a);
	}
	else
	{
		while (stack_a->head != top)
			ft_rev_rotate(stack_a);
	}
}

void	recursive_quicksort(int low, int high, t_stack *src, t_stack *dest)
{
	
}

void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*pivot;
	t_node	*temp;
	t_node	*tail;

	temp = stack_a->head;
	tail = stack_a->tail;
	pivot = find_node(*stack_a, medium(*stack_a, stack_a->tail));
	send_pivot(stack_a, stack_b, pivot);
	while (temp)
	{
		if (temp->value < pivot->value)
			ft_push(stack_a, stack_b);
		else
			ft_rotate(stack_a);
		if (temp == tail)
			break ;
		temp = temp->next;
	}
}
