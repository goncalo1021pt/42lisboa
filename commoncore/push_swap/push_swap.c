/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:13:19 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/17 12:31:39 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	free_all(char **in)
{
	int	ctd;

	ctd = 0;
	while (in[ctd])
		free(in[ctd++]);
}

void	initialize_stack(t_list_data *stack_a)
{
	stack_a->head = NULL;
	stack_a->tail = NULL;
}

int	main(int argc, char **argv)
{
	t_list_data	stack_a;
	char		**read;

	initialize_stack(&stack_a);
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
		ft_dlb_print(&stack_a);
	}
	return (0);
}
