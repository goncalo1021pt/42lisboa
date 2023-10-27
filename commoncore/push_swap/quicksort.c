/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:04:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/27 11:11:08 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

t_stack *find_stack(t_stack *stack_a, t_stack *stack_b, t_node *find)
{
	t_node	*current;

	while (current)
	{
		if (current == find)
			return (stack_a);
		current = current->next;
	}
	return (stack_b);
}

void	recursive_quicksort(t_node *low, t_node *high, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*pivot;
	t_stack	*current;

	current = find_stack(stack_a, stack_b, low);
	pivot = find_node(*stack_a, medium(stack_a->head, stack_a->tail));
}

void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tail;
	t_node	*temp;
	t_node	*pivot;

	temp = stack_a->head;
	tail = stack_a->tail;
	pivot = find_node(*stack_a, medium(stack_a->head, stack_a->tail));
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
	//recursive_quicksort(stack_b->head, stack_b->tail, stack_a, stack_b);
	pivot = find_last_not_sorted(stack_a);
	//recursive_quicksort(stack_a->head, pivot, stack_a, stack_b);
}
