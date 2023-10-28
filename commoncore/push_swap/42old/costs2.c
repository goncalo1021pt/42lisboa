/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:55:46 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/28 13:03:00 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	one_element_cost(t_stack stack, t_next_elements *elem)
{
	int		cost_head;
	int		cost_tail;
	int		head_value;
	int		tail_value;

	cost_head = head_cost(stack.head, elem);
	head_value = stack.head->value;
	cost_tail = tail_cost(stack.tail, elem);
	tail_value = stack.tail->value;
	if (cost_head > cost_tail)
	{
		elem->cost += cost_tail;
		elem->found = head_value;
	}
	else
	{
		elem->cost += cost_head;
		elem->found = tail_value;
	}
}

int	head_cost(t_node *temp, t_next_elements *elem)
{
	int	cost_head;

	cost_head = 0;
	while (not_in_array(temp->value, 3, elem->nbr))
	{
		cost_head++;
		temp = temp->next;
	}
	elem->found = temp->value;
	return (cost_head);
}

int	tail_cost(t_node *temp, t_next_elements *elem)
{
	int		cost_tail;

	cost_tail = 1;
	while (not_in_array(temp->value, 3, elem->nbr))
	{
		cost_tail++;
		temp = temp->prev;
	}
	elem->found = temp->value;
}
