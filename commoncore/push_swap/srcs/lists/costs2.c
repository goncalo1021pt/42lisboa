/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:07:51 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/08 12:55:17 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	all_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	temp = stack_a->head;
	while (temp)
	{
		temp->cost.head = head_cost(stack_a, temp);
		temp->cost.tail = tail_cost(stack_a, temp);
		temp = temp->next;
	}
	temp = stack_b->head;
	while (temp)
	{
		temp->cost.head = head_cost(stack_b, temp);
		temp->cost.tail = tail_cost(stack_b, temp);
		temp->cost.best = best_friend(stack_a, temp);
		temp = temp->next;
	}
}

t_node	*best_friend(t_stack *stack_a, t_node *node)
{
	t_node	*temp;
	t_node	*best;
	int		best_value;

	temp = stack_a->head;
	best_value = INT_MAX;
	while (temp)
	{
		if (temp->value > node->value && temp->value < best_value)
		{
			best_value = temp->value;
			best = temp;
		}
		temp = temp->next;
	}
	return (best);
}

void	small_cost(t_node *current, int 
	*head_cost, int *tail_cost, int *diff_cost)
{
	if (current->cost.head > current->cost.best->cost.head)
		*head_cost = current->cost.head;
	else
		*head_cost = current->cost.best->cost.head;
	if (current->cost.tail > current->cost.best->cost.tail)
		*tail_cost = current->cost.tail;
	else
		*tail_cost = current->cost.best->cost.tail;
	if (current->cost.head < current->cost.tail)
		*diff_cost = current->cost.head;
	else
		*diff_cost = current->cost.tail;
	if (current->cost.best->cost.head < current->cost.best->cost.tail)
		*diff_cost += current->cost.best->cost.head;
	else
		*diff_cost += current->cost.best->cost.tail;
}

void	select_low(int *head_cost, int 
	*tail_cost, int *diff_cost, t_node *current)
{
	if (*head_cost < *diff_cost)
	{
		current->cost.direction = 'h';
		current->cost.total = *head_cost;
	}
	else if (*tail_cost < *diff_cost)
	{
		current->cost.direction = 't';
		current->cost.total = *tail_cost;
	}
	else
	{
		current->cost.direction = 'd';
		current->cost.total = *diff_cost;
	}
}

t_node	*total_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*lowest;
	int		head_cost;
	int		tail_cost;
	int		diff_cost;

	all_costs(stack_a, stack_b);
	current = stack_b->head;
	lowest = current;
	while (current != NULL)
	{
		small_cost(current, &head_cost, &tail_cost, &diff_cost);
		select_low(&head_cost, &tail_cost, &diff_cost, current);
		if (lowest->cost.total > current->cost.total)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}
