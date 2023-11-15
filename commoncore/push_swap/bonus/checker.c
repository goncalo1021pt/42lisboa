/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:45:40 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/14 14:40:15 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
			checker(&stack_a, &stack_b);
			free_all(read);
		}
	}
	else if (argc > 2)
	{
		if (!save_stack(argv, &stack_a, 1))
			write(2, "Error\n", 6);
		else
			checker(&stack_a, &stack_b);
	}
	return (0);
}
