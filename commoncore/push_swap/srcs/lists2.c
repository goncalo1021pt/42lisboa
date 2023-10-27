/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:26:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/27 11:14:14 by gfontao-         ###   ########.fr       */
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

t_node	*find_node(t_stack stack, int value)
{
	while (stack.head->value != value)
	{
		if (stack.head == stack.tail)
			return (NULL);
		stack.head = stack.head->next;
	}
	return (stack.head);
}

t_bool	is_sorted(t_node *low)
{
	t_node	*temp;

	temp = low;
	while (temp)
	{
		if (temp->prev && temp->value < temp->prev->value)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}
