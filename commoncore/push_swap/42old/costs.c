/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:26:13 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/30 11:57:53 by gfontao-         ###   ########.fr       */
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

void	get_small(t_stack stack, t_next_elements *elem)
{
	int		ctd;
	int		small;

	ctd = 0;
	while (ctd < 4)
	{
		small = stack.head->value;
		while (stack.head)
		{
			if (not_in_array(stack.head->value, ctd, elem->nbr) && small > stack.head->value)
				small = stack.head->value;
			stack.head = stack.head->next;
		}
		elem->nbr[ctd] = small;
		ctd++;
	}
}

void	get_big_4(t_stack stack, t_next_elements *elem)
{
	int		ctd;
	int		big;

	ctd = 0;
	while (ctd < 4)
	{
		big = stack.head->value;
		while (stack.head)
		{
			if (not_in_array(stack.head->value, ctd, elem->nbr) && big < stack.head->value)
				big = stack.head->value;
			stack.head = stack.head->next;
		}
		elem->nbr[ctd] = big;
		elem->nbr_check[ctd] = big;
		ctd++;
	}
}

int	total_cost(t_stack stack, t_next_elements *big, t_next_elements *small)
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
