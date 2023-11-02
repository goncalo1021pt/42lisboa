/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:04:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/02 12:32:24 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_stack(t_stack *stack_a, t_stack *stack_b, t_node *find)
{
	t_node	*current;

	current = stack_a->head;
	while (current)
	{
		if (current == find)
			return (stack_a);
		current = current->next;
	}
	return (stack_b);
}

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
}

/* void	restore(t_stack *stack, t_node *top)
{
	if (head_cost(stack, top) < tail_cost(stack, top))
	{
		while (stack->head != top)
			ft_rotate(stack);
	}
	else
	{
		while (stack->head != top)
			ft_rev_rotate(stack);
	}
} */

void	quicksort_ab(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	t_node	*tail;
	t_val	val;
	int init_min;
	int init_max;

	init_max = max;
	init_min = min;
	val.mc = -1;
	while (!is_sorted(stack_a))
	{
		if (stack_a->size <= 10 || init_max - init_min < 10)
		{
			small_sort(stack_a, stack_b);
			break ;
		}
		medium(min, max, &val);
		tail = stack_a->tail;
		while ((stack_a->head != tail && stack_b->head != tail && stack_b->tail != tail) || stack_a->head->value < val.med[val.mc])
		{
			if (is_sorted(stack_a))
				break ;
			if (stack_a->head->value > val.med[val.mc])
				interpreter(stack_a, stack_b, "ra");
			if (stack_a->head->value <= val.med[val.mc])
			{
				interpreter(stack_a, stack_b, "pb");
				if (stack_b->head->value < val.quarter[val.mc] && stack_b->size > 1)
					interpreter(stack_a, stack_b, "rb");
			}
		}
		min_max(stack_a, &min, &max);
	}
	if (val.mc != -1)
		quicksort_ba(stack_a, stack_b, &val);
}

void	quicksort_ba(t_stack *stack_a, t_stack *stack_b, t_val *val)
{
	int	temp;

	while (val->mc > -1)
	{ 
		while (stack_b->size && stack_b->head->value >= val->quarter[val->mc])
			interpreter(stack_a, stack_b, "pa");
		quicksort_ab(stack_a, stack_b, val->quarter[val->mc], val->med[val->mc]);
		if (val->mc - 1 < 0)
			temp = 1;
		else
			temp = val->med[val->mc - 1];
		while (stack_b->size && stack_b->tail->value >= temp)
		{
			if (val->mc > 0)
				interpreter(stack_a, stack_b, "rrb");
			interpreter(stack_a, stack_b, "pa");
		}
		quicksort_ab(stack_a, stack_b, temp, val->quarter[val->mc] - 1);
		val->mc--;
	}
}
