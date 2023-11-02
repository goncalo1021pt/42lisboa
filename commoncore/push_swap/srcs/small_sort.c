/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:44:07 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/02 12:23:19 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head->value > stack_a->head->next->value)
	{
		if (stack_a->head->value > stack_a->tail->value)
			interpreter(stack_a, stack_b, "ra");
		if (stack_a->head->value > stack_a->head->next->value)
			interpreter(stack_a, stack_b, "sa");
	}
	else if (stack_a->tail->value < stack_a->tail->prev->value)
	{
		interpreter(stack_a, stack_b, "rra");
		if (stack_a->head->value > stack_a->head->next->value)
			interpreter(stack_a, stack_b, "sa");
	}
}

t_node	*get_small(t_stack *stack)
{
	t_node	*small;
	t_node	*current;

	small = stack->head;
	current = stack->head;
	while (current != NULL)
	{
		if (small->value > current->value)
			small = current;
		current = current->next;
	}
	return (small);
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*small;
	t_node	*first;

	first = get_small(stack_a);
	while (!is_sorted(stack_a) && stack_a->size > 3)
	{
		small = get_small(stack_a);
		if (stack_a->size / 2 > head_cost(stack_a, small))
			while (stack_a->head != small)
				interpreter(stack_a, stack_b, "ra");
		else
			while (stack_a->head != small)
				interpreter(stack_a, stack_b, "rra");
		interpreter(stack_a, stack_b, "pb");
	}
	sort_3(stack_a, stack_b);
	while (stack_a->head != first)
		interpreter(stack_a, stack_b, "pa");
}
