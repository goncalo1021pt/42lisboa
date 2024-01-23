/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:13:19 by gfontao-          #+#    #+#             */
/*   Updated: 2024/01/22 18:08:37 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
