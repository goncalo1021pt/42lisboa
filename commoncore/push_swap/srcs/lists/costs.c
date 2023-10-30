/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:39:16 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/30 15:00:45 by gfontao-         ###   ########.fr       */
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

void	medium(t_node *low, t_node *high, t_val *val)
{
	int		max;
	int		min;
	t_node	*current;

	val->mc++;
	current = low;
	max = low->value;
	min = low->value;
	while (current != high)
	{
		if (max < current->value)
			max = current->value;
		if (min > current->value)
			min = current->value;
		current = current->next;
	}
	val->med[val->mc] = (max + min) / 2;
	val->qurter[val->mc] = (val->med[val->mc] + min) / 2;
}

t_node	*find_last_not_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->tail;
	/* while (current->prev->value < current->value)
	{
		current = current->prev;
	} */
	return (current->prev);
}
