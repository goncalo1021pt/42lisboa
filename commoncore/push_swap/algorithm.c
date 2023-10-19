/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:26:13 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/19 13:32:53 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	indexer(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;
	int		ctd;

	temp = stack->head;
	temp2 = stack->head;
	while (temp)
	{
		ctd = 1;
		while (temp2)
		{
			if (temp2->nbr < temp->nbr)
				ctd++;
			temp2 = temp2->next;
		}
		temp->value = ctd;
		temp2 = stack->head;
		temp = temp->next;
	}
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
	temp = stack->tail;
	while (not_in_array(temp->value, 3, elem->nbr))
	{
		cost_tail++;
		temp = temp->prev;
	}
	if (cost_head > cost_tail)
		elem->cost += cost_tail;
	else
		elem->cost += cost_head;
}

t_bool	not_in_array(int nbr, int i, int *array)
{
	while (i >= 0)
		if (array[i--] == nbr)
			return (FALSE);
	return (TRUE);
}

/* void	sort(t_stack a, t_stack b)
{
	
} */

/* 	temp = elements.nbr[ctd];
			elements.nbr[ctd] = temp->value;
			while (elements.nbr[ctd])
			{

				ctd++;
			}
			elements.nbr[ctd] = temp->value; */