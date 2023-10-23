/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:26:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/20 10:43:41 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_dbl_clear(t_stack *stack)
{
	t_node	*temp;

	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
	stack->head = NULL;
	stack->tail = NULL;
}

t_bool	ft_dbl_not_equal(t_stack *stack, int content)
{
	t_node	*temp;

	temp = stack->head;
	while (temp)
	{
		if (temp->nbr == content)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

t_bool	is_sorted(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp)
	{
		if (temp->prev && temp->value < temp->prev->value)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

int	is_ordered(t_stack *stack)
{
	t_node	*temp;
	int		sort_state;

	sort_state = 2;
	temp = stack->head;
	while (temp)
	{
		if (temp->prev && temp->value < temp->prev->value)
		{
			sort_state--;
			if (sort_state == 0)
				break ;
		}
		temp = temp->next;
	}
	if (sort_state == 1 && stack->head->value < stack->tail->value)
		sort_state--;
	return (sort_state);
}
