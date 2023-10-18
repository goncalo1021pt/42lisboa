/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:37:21 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/18 12:14:09 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

long	ft_atoi_long(char *nptr)
{
	int		ctd;
	int		signal;
	long	result;

	ctd = 0;
	signal = 1;
	result = 0;
	while (nptr[ctd] == ' ' || (nptr[ctd] >= 9 && nptr[ctd] <= 13))
		ctd++;
	if (nptr[ctd] == '+' || nptr[ctd] == '-')
		if (nptr[ctd++] == '-')
			signal = -signal;
	while (nptr[ctd] <= '9' && nptr[ctd] >= '0')
	{
		result *= 10;
		result += nptr[ctd++] - '0';
	}
	return (signal * result);
}

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
		ctd++;
	}
	if (len > 11)
		flag = 0;
	else
	{
		if (flag == 1)
			if (INT_MAX < ft_atoi_long(input) || INT_MIN
				> ft_atoi_long(input))
				flag = 0;
	}
	return (flag);
}

int	save_stack(char **input, t_stack *stack_a)
{
	int		ctd;
	t_node	*node;

	ctd = 1;
	while (input[ctd])
	{
		if (valid_input(input[ctd]) && ft_dbl_not_equal(stack_a, ft_atoi(input[ctd])))
		{
			node = ft_dbl_new(ft_atoi(input[ctd]));
			ft_dbl_add_back(stack_a, node);
		}
		else
		{
			ft_dbl_clear(stack_a);
			return (0);
		}
		ctd++;
	}
	return (1);
}
