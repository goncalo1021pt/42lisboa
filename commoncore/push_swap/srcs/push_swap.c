/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:13:19 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/30 10:42:43 by gfontao-         ###   ########.fr       */
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
	stack_a->size = 0;
	stack_b->size = 0;
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
		if (!read && !save_stack(argv, &stack_a))
			write(2, "Error\n", 6);
		if (read)
			free_all(read);
	}
	else if (argc > 2)
	{
		if (!save_stack(argv, &stack_a))
			write(2, "Error\n", 6);
		ft_dbl_print(&stack_a);
		printf("stack a:\n");
		quicksort_ab(&stack_a, &stack_b);
		ft_dbl_print(&stack_a);
		printf("stack b:\n");
		ft_dbl_print(&stack_b);
	}
	ft_dbl_clear(&stack_a);
	return (0);
}
