/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:13:19 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/08 13:41:42 by gfontao-         ###   ########.fr       */
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

	min_max(stack_a, &min, &max);
	quicksort_ab(stack_a, stack_b, min, max);
	ft_dbl_clear(stack_a);
	ft_dbl_clear(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**read;

	initialize_stack(&stack_a, &stack_b);
	if (argc == 2)
	{
		read = ft_split(argv[1], ' ');
		if (!read || !save_stack(read, &stack_a, 0))
			write(2, "Error\n", 6);
		else
		{
			sort(&stack_a, &stack_b);
			free_all(read);
		}
	}
	else if (argc > 2)
	{
		if (!save_stack(argv, &stack_a, 1))
			write(2, "Error\n", 6);
		else
			sort(&stack_a, &stack_b);
	}
	return (0);
}
