/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:28:55 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/14 16:07:17 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(char **in)
{
	int	ctd;

	ctd = 0;
	while (in[ctd])
		free(in[ctd++]);
}

void	initialize_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_a->order = ASCENDING;
	stack_b->order = DESCENDING;
	stack_a->size = 0;
	stack_b->size = 0;
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;

	if (is_sorted(stack_a))
		return ;
	min_max(stack_a, &min, &max);
	quicksort_ab(stack_a, stack_b, min, max);
	ft_dbl_clear(stack_a);
	ft_dbl_clear(stack_b);
}
