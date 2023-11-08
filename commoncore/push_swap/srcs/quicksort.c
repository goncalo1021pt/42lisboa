/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:04:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/08 11:58:48 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	interpreter(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (!ft_strncmp(str, "sa", 2) && ft_printf("sa\n"))
		ft_swap_01(stack_a);
	else if (!ft_strncmp(str, "pb", 2) && ft_printf("pb\n"))
		ft_push(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra", 2) && ft_printf("ra\n"))
		ft_rotate(stack_a);
	else if (!ft_strncmp(str, "rra", 3) && ft_printf("rra\n"))
		ft_rev_rotate(stack_a);
	else if (!ft_strncmp(str, "sb", 2) && ft_printf("sb\n"))
		ft_swap_01(stack_b);
	else if (!ft_strncmp(str, "pa", 2) && ft_printf("pa\n"))
		ft_push(stack_b, stack_a);
	else if (!ft_strncmp(str, "rb", 2) && ft_printf("rb\n"))
		ft_rotate(stack_b);
	else if (!ft_strncmp(str, "rrb", 3) && ft_printf("rrb\n"))
		ft_rev_rotate(stack_b);
	else
		mutual_interpreter(stack_a, stack_b, str);
}

void	mutual_interpreter(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (!ft_strncmp(str, "rrr", 3) && ft_printf("rrr\n"))
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
	}
	else if (!ft_strncmp(str, "rr", 2) && ft_printf("rr\n"))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}

void	medium(int min, int max, t_val *val)
{
	val->med = (max + min) / 2;
	val->quarter = (val->med + min) / 2;
}

int	send_b(t_stack *stack_a, t_stack *stack_b, t_val val, int max)
{
	if (is_sorted(stack_a) || stack_a->head->value > max)
		return (get_big(stack_a)->value);
	if (stack_a->head->value > val.med)
		interpreter(stack_a, stack_b, "ra");
	if (stack_a->head->value <= val.med)
	{
		interpreter(stack_a, stack_b, "pb");
		if (stack_b->head->value < val.quarter && stack_b->size > 1)
			interpreter(stack_a, stack_b, "rb");
	}
	return (get_big(stack_a)->value);
}

void	quicksort_ab(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	t_node	*tail;
	t_val	val;
	int		big;

	while (!is_sorted(stack_a))
	{
		if (stack_a->size <= 10 || max - min < 10)
		{
			small_sort(stack_a, stack_b);
			break ;
		}
		medium(min, max, &val);
		tail = stack_a->tail;
		while ((stack_a->head != tail && stack_b->head != tail 
				&& stack_b->tail != tail) || stack_a->head->value < val.med)
			big = send_b(stack_a, stack_b, val, max);
		if (max != big)
			while (stack_a->tail->value != big)
				interpreter(stack_a, stack_b, "rra");
		min = get_small(stack_a)->value;
	}
	if (stack_b->size > 0)
		sort_ba(stack_a, stack_b);
}
