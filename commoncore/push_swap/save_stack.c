/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:37:21 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/14 09:05:41 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	free_all(void);

int	save_stack(char **input, t_stack **stack_a)
{
	int		ctd;
	t_stack	*new;

	ctd = 0;
	while (input)
	{
		while ((*input)[ctd])
		{
			if (ctd == 0 && !((*input)[ctd] == '-' || (*input)[ctd] == '+'))
				if (!((*input)[ctd] >= '0' && (*input)[ctd] <= '9'))
					return (free_all());
		}
		new = ft_lstnew(ft_atoi(*input));
		if (!new)
			ft_dbl_lstadd_back(stack_a);
		input++;
	}
	return (1);
}
