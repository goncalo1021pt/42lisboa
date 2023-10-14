/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:16:26 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/14 18:20:34 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_01(t_list_data **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!stack || !(*stack)->head || !(*stack)->head->next)
		return (NULL);
	temp = ft_dbl_rem_front(stack);
	temp2 = ft_dbl_rem_front(stack);
	ft_dbl_add_front(stack, temp);
	ft_dbl_add_front(stack, temp2);
}

void	ft_rotate(t_list_data **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack)->head || !(*stack)->head->next)
		return (NULL);
	temp = ft_dbl_rem_front(stack);
	ft_dbl_add_back(stack, temp);
}

void	ft_rev_rotate(t_list_data **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack)->head || !(*stack)->head->next)
		return (NULL);
	temp = ft_dbl_rem_back(stack);
	ft_dbl_add_front(stack, temp);
}

void	ft_dlb_print(t_list_data **stack)
{
	t_stack	*temp;

	temp = (*stack)->head;
	while (!temp)
	{
		temp = temp->next;
		p
	}
}
