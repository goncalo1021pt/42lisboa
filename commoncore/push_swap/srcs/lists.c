/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:56:47 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/27 16:37:02 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_dbl_new(int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->nbr = content;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ft_dbl_add_front(t_stack *stack, t_node *new)
{
	if (!stack->head)
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
	new->next = stack->head;
	stack->head->prev = new;
	stack->head = new;
	}
}

void	ft_dbl_add_back(t_stack *stack, t_node *new)
{
	if (!stack->tail)
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		stack->tail->next = new;
		new->prev = stack->tail;
		stack->tail = new;
	}
}

t_node	*ft_dbl_rem_front(t_stack *stack)
{
	t_node	*temp;

	if (!stack->head || !stack->tail)
		return (NULL);
	temp = stack->head;
	if (temp->next)
	{
		stack->head = temp->next;
		temp->next->prev = NULL;
	}
	else
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

t_node	*ft_dbl_rem_back(t_stack *stack)
{
	t_node	*temp;

	if (!stack->head || !stack->tail)
		return (NULL);
	temp = stack->tail;
	if (temp->prev)
	{
		stack->tail = temp->prev;
		temp->prev->next = NULL;
	}
	else
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}
