/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:44:07 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/30 13:04:08 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->head->value > stack->head->next->value)
	{
		if (stack->head->value > stack->tail->value)
			ft_rotate(stack);
		if (stack->head->value > stack->head->next->value)
			ft_swap_01(stack);
	}
	else if (stack->tail->value < stack->tail->prev->value)
	{
		ft_rev_rotate(stack);
		if (stack->head->value > stack->head->next->value)
			ft_swap_01(stack);
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
				ft_rotate(stack_a);
		else
			while (stack_a->head != small)
				ft_rev_rotate(stack_a);
		ft_push(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (stack_a->head != first)
		ft_push(stack_b, stack_a);
}
