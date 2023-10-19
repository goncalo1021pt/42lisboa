/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:26:13 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/19 11:44:48 by gfontao-         ###   ########.fr       */
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

int	*get_samll_4(t_stack *stack, t_next_elements elements)
{
	t_node	*temp;
	int		ctd;

	temp = stack->head;
	while (temp)
	{
		ctd = 0;
		if (!elements.nbr || temp->value < elements.nbr[ctd])
		{
			while (elements.nbr[ctd])
			{
				elements.nbr[ctd] = temp->value;
				ctd++;
			}
		}
		temp = temp->next;
	}
}

/* void	sort(t_stack a, t_stack b)
{
	
} */