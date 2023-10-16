/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:37:21 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/15 14:52:40 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	valid_input(char *input)
{
	int	len;
	int	flag;
	int	ctd;

	ctd = 0;
	flag = 1;
	len = ft_strlen(input);
	while (input[ctd])
	{
		if (ctd == 0 && (input[ctd] == '+' || input[ctd] == '+'))
			flag = 1;
		else if (!ft_isdigit(input[ctd]))
			flag = 0;
	}
	if (len > 11)
		flag = 0;
	return (flag);
}

int	save_stack(char **input, t_stack *stack_a)
{
	int		ctd;

	ctd = 0;
	while (input)
	{
		while ((*input)[ctd])
		{
		}
		if (!new)
			ft_dbl_lstadd_back(stack_a);
		input++;
	}
	return (1);
}
