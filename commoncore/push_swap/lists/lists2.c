/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:26:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/15 12:31:44 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_dbl_clear(t_list_data *stack)
{
	t_stack	*temp;

	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
	stack->head = NULL;
	stack->tail = NULL;
}
