/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:30:50 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/08 17:44:02 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void checker(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*list;

	list = get_moves();
	while (list)
	{
		if (!interpreter2(stack_a, stack_b, (char *)list->content))
			break ;
		list = list->next;
	}
	if (is_sorted(stack_a) && stack_b->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

t_list *get_moves(void)
{
	t_list	*list;
	char	*line;

	while (TRUE)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		ft_lstadd_back(&list, ft_lstnew((void *)line));
		free(line);
	}
	return (list);
}

t_bool	interpreter2(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (!ft_strncmp(str, "sa", 2))
		ft_swap_01(stack_a);
	else if (!ft_strncmp(str, "pb", 2))
		ft_push(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra", 2))
		ft_rotate(stack_a);
	else if (!ft_strncmp(str, "rra", 3))
		ft_rev_rotate(stack_a);
	else if (!ft_strncmp(str, "sb", 2))
		ft_swap_01(stack_b);
	else if (!ft_strncmp(str, "pa", 2))
		ft_push(stack_b, stack_a);
	else if (!ft_strncmp(str, "rb", 2))
		ft_rotate(stack_b);
	else if (!ft_strncmp(str, "rrb", 3))
		ft_rev_rotate(stack_b);
	else
		return (mutual_interpreter2(stack_a, stack_b, str));
	return (TRUE);
}

t_bool	mutual_interpreter2(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (!ft_strncmp(str, "rrr", 3))
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
	}
	else if (!ft_strncmp(str, "rr", 2))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else
	{
		ft_putendl_fd("KO", 2);
		return (FALSE);
	}
	return (TRUE);
}
