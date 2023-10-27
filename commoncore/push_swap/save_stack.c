/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:37:21 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/27 14:27:18 by gfontao-         ###   ########.fr       */
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
	int		len;
	t_bool	flag;
	int		ctd;

	ctd = 0;
	flag = TRUE;
	len = ft_strlen(input);
	while (input[ctd])
	{
		if (ctd == 0 && (input[ctd] == '+' || input[ctd] == '-'))
			flag = TRUE;
		else if (!ft_isdigit(input[ctd]))
			flag = FALSE;
		ctd++;
	}
	if (len > 11)
		flag = FALSE;
	else
	{
		if (flag == TRUE)
			if (INT_MAX < ft_atoi_long(input) || INT_MIN
				> ft_atoi_long(input))
				flag = FALSE;
	}
	return (flag);
}

void	indexer(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;
	int		ctd;

	temp = stack->head;
	while (temp)
	{
		ctd = 1;
		temp2 = stack->head;
		while (temp2)
		{
			if (temp2->nbr < temp->nbr)
				ctd++;
			temp2 = temp2->next;
		}
		temp->value = ctd;
		temp = temp->next;
	}
}

t_bool	save_stack(char **input, t_stack *stack_a)
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
			return (FALSE);
		}
		ctd++;
	}
	indexer(stack_a);
	stack_a->size = ctd - 1;
	return (TRUE);
}
