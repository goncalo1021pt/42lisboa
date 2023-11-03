/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:39:16 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/03 11:24:26 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	head_cost(t_stack *stack, t_node *small)
{
	int		cost;
	t_node	*current;

	cost = 0;
	current = stack->head;
	while (current != small)
	{
		cost++;
		current = current->next;
	}
	return (cost);
}

int	tail_cost(t_stack *stack, t_node *pivot)
{
	int		cost_tail;
	t_node	*current;

	current = stack->tail;
	cost_tail = 1;
	while (current != pivot)
	{
		cost_tail++;
		current = current->prev;
	}
	return (cost_tail);
}

void	min_max(t_stack *stack, int *min, int *max)
{
	t_node	*current;

	current = stack->head;
	*min = stack->head->value;
	*max = stack->head->value;
	while (current)
	{
		if (*min > current->value)
			*min = current->value;
		else if (*max < current->value)
			*max = current->value;
		current = current->next;
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

t_node	*get_big(t_stack *stack)
{
	t_node	*big;
	t_node	*current;

	big = stack->head;
	current = stack->head;
	while (current != NULL)
	{
		if (big->value < current->value)
			big = current;
		current = current->next;
	}
	return (big);
}