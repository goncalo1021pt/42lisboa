/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:39:16 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/31 16:51:37 by gfontao-         ###   ########.fr       */
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

void	medium(int min, int max, t_val *val)
{

	val->mc++;
	val->med[val->mc] = (max + min) / 2;
	val->quarter[val->mc] = (val->med[val->mc] + min) / 2;
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
