/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:26:13 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/19 20:33:00 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_bool	not_in_array(int nbr, int i, int *array)
{
	while (i >= 0)
		if (array[i--] == nbr)
			return (FALSE);
	return (TRUE);
}

void	get_small_4(t_stack *stack, t_next_elements *elem)
{
	t_node	*tmp;
	int		ctd;
	int		small;

	ctd = 0;
	while (ctd < 4)
	{
		tmp = stack->head;
		small = tmp->value;
		while (tmp)
		{
			if (not_in_array(tmp->value, ctd, elem->nbr) && small > tmp->value)
				small = tmp->value;
			tmp = tmp->next;
		}
		elem->nbr[ctd] = small;
		ctd++;
	}
}

void	get_big_4(t_stack *stack, t_next_elements *elem)
{
	t_node	*tmp;
	int		ctd;
	int		big;

	ctd = 0;
	while (ctd < 4)
	{
		tmp = stack->head;
		big = tmp->value;
		while (tmp)
		{
			if (not_in_array(tmp->value, ctd, elem->nbr) && big < tmp->value)
				big = tmp->value;
			tmp = tmp->next;
		}
		elem->nbr[ctd] = big;
		elem->nbr_check[ctd] = big;
		ctd++;
	}
}

void	one_element_cost(t_stack *stack, t_next_elements *elem)
{
	int		cost_head;
	int		cost_tail;
	t_node	*temp;

	temp = stack->head;
	cost_head = 0;
	cost_tail = 1;
	while (not_in_array(temp->value, 3, elem->nbr))
	{
		cost_head++;
		temp = temp->next;
	}
	elem->found = temp->value;
	temp = stack->tail;
	while (not_in_array(temp->value, 3, elem->nbr))
	{
		cost_tail++;
		temp = temp->prev;
	}
	if (cost_head > cost_tail)
		elem->cost += cost_tail;
	if (cost_head > cost_tail)
		elem->found = temp->value;
	else
		elem->cost += cost_head;
}

int	total_cost(t_stack *stack, t_next_elements *big, t_next_elements *small)
{
	int	ctd;

	small->cost = 0;
	big->cost = 0;
	ctd = -1;
	get_small_4(stack, small);
	get_big_4(stack, big);
	while (small->total_found > 0)
	{
		one_element_cost(stack, small);
		while (++ctd < 4)
			if (small->found == small->nbr_check[ctd])
				small->nbr_check[ctd] = 0;
		small->total_found--;
	}
	while (big->total_found > 0)
	{
		one_element_cost(stack, big);
		while (++ctd < 4)
			if (big->found == big->nbr_check[ctd])
				big->nbr_check[ctd] = 0;
		big->total_found--;
	}
}
