/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:59:29 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/08 11:10:33 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void head_direction(t_stack *stack_a, t_stack *stack_b, t_node *lowest)
{
	while (stack_a->head != lowest->cost.best && stack_b->head != lowest)
		interpreter(stack_a, stack_b, "rr");
	if (stack_a->head != lowest->cost.best)
		while (stack_a->head != lowest->cost.best)
			interpreter(stack_a, stack_b, "ra");
	else if (stack_b->head != lowest)
		while (stack_b->head != lowest)
			interpreter(stack_a, stack_b, "rb");
	interpreter(stack_a, stack_b, "pa");
}

void tail_direction(t_stack *stack_a, t_stack *stack_b, t_node *lowest)
{
	while (stack_a->head != lowest->cost.best && stack_b->head != lowest)
		interpreter(stack_a, stack_b, "rrr");
	if (stack_a->head != lowest->cost.best)
		while (stack_a->head != lowest->cost.best)
			interpreter(stack_a, stack_b, "rra");
	else if (stack_b->head != lowest)
		while (stack_b->head != lowest)
			interpreter(stack_a, stack_b, "rrb");
	interpreter(stack_a, stack_b, "pa");
}

void diff_direction(t_stack *stack_a, t_stack *stack_b, t_node *lowest)
{
	while (stack_a->head != lowest->cost.best)
	{
		if (lowest->cost.best->cost.head < lowest->cost.best->cost.tail)
			interpreter(stack_a, stack_b, "ra");
		else if (lowest->cost.best->cost.head > lowest->cost.best->cost.tail)
			interpreter(stack_a, stack_b, "rra");
	}
	while (stack_b->head != lowest)
	{
		if (lowest->cost.head < lowest->cost.tail)
			interpreter(stack_a, stack_b, "rb");
		else if (lowest->cost.head > lowest->cost.tail)
			interpreter(stack_a, stack_b, "rrb");
	}
	interpreter(stack_a, stack_b, "pa");
}

void	sort_ba(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*lowest;
	while (stack_b->size > 0)
	{
		lowest = total_cost(stack_a, stack_b);
		if (lowest->cost.direction == 'h')
			head_direction(stack_a, stack_b, lowest);
		else if (lowest->cost.direction == 't')
			tail_direction(stack_a, stack_b, lowest);
		else if (lowest->cost.direction == 'd')
			diff_direction(stack_a, stack_b, lowest);
	}
	lowest = get_small(stack_a);
	all_costs(stack_a, stack_b);
	while (stack_a->head != lowest)
	{
	if (lowest->cost.head < lowest->cost.tail)
		interpreter(stack_a, stack_b, "ra");
	else if (lowest->cost.head > lowest->cost.tail)
		interpreter(stack_a, stack_b, "rra");
	}
}
