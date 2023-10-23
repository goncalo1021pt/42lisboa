/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:39:16 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/23 08:59:26 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	head_cost(t_node *temp, t_node *pivot)
{
	int	cost_head;

	cost_head = 0;
	while (temp != pivot)
	{
		cost_head++;
		temp = temp->next;
	}
	return (cost_head);
}

int	tail_cost(t_node *temp, t_node *pivot)
{
	int		cost_tail;

	cost_tail = 1;
	while (temp != pivot)
	{
		cost_tail++;
		temp = temp->prev;
	}
	return (cost_tail);
}
