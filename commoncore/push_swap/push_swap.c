/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:13:19 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/22 15:43:08 by gfontao-         ###   ########.fr       */
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

void	initialize_stack(t_stack *stack_a)
{
	stack_a->head = NULL;
	stack_a->tail = NULL;
}

void	indexer(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;
	int		ctd;

	temp = stack->head;
	temp2 = stack->head;
	while (temp)
	{
		ctd = 1;
		while (temp2)
		{
			if (temp2->nbr < temp->nbr)
				ctd++;
			temp2 = temp2->next;
		}
		temp->value = ctd;
		temp2 = stack->head;
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**read;

	initialize_stack(&stack_a);
	initialize_stack(&stack_b);
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
