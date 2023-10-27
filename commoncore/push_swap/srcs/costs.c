/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:39:16 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/27 17:08:26 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	head_cost(t_stack *stack, t_node *pivot)
{
	int		cost_head;
	t_node	*current;

	current = stack->head;
	cost_head = 0;
	while (current != pivot)
	{
		cost_head++;
		current = current->next;
	}
	return (cost_head);
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

int	medium(t_node *low, t_node *high)
{
	int		max;
	int		min;
	t_node	*current;

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
	return ((max + min) / 2);
}

t_node	*find_last_not_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->tail;
	ft_dlb_print();
	/* while (current->prev->value < current->value)
	{
		current = current->prev;
	} */
	return (current->prev);
}
