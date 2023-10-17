/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:13:19 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/17 11:59:21 by gfontao-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list_data	stack_a;
	char		**read;

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
		ft_printf("testing\n");
		if (!save_stack(argv, &stack_a))
			write(2, "Error\n", 6);
	}
	return (0);
}
