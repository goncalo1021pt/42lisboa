/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:04:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/03 13:44:56 by gfontao-         ###   ########.fr       */
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

void	medium(int min, int max, t_val *val)
{

	val->mc++;
	val->med[val->mc] = (max + min) / 2;
	val->quarter[val->mc] = (val->med[val->mc] + min) / 2;
}

void	quicksort_ab(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	t_node	*tail;
	t_val	val;
	int		big;

	val.mc = -1;
	while (!is_sorted(stack_a))
	{
		ft_printf("max = %d, min = %d\n", max, min);
		if (stack_a->size <= 10 || max - min < 10)
		{
			small_sort(stack_a, stack_b);
			break ;
		}
		medium(min, max, &val);
		tail = stack_a->tail;
		while ((stack_a->head != tail && stack_b->head != tail && stack_b->tail != tail) || stack_a->head->value < val.med[val.mc])
		{
			if (is_sorted(stack_a) || stack_a->head->value > max)
				break ;
			if (stack_a->head->value > val.med[val.mc])
				interpreter(stack_a, stack_b, "ra");
			if (stack_a->head->value <= val.med[val.mc])
			{
				interpreter(stack_a, stack_b, "pb");
				if (stack_b->head->value < val.quarter[val.mc] && stack_b->size > 1)
					interpreter(stack_a, stack_b, "rb");
			}
		 	big = get_big(stack_a)->value;
		}
		if (max != big)
			while (stack_a->tail->value != big)
				interpreter(stack_a, stack_b, "rra");
		min = get_small(stack_a)->value;
	}
	/*if (val.mc != -1)
		quicksort_ba(stack_a, stack_b, &val);*/
}

/* void	quicksort_ba(t_stack *stack_a, t_stack *stack_b, t_val *val)
{
	int	temp;

	while (val->mc > -1)
	{ 
		while (stack_b->size && stack_b->head->value >= val->quarter[val->mc])
			interpreter(stack_a, stack_b, "pa");
		quicksort_ab(stack_a, stack_b, val->quarter[val->mc], val->med[val->mc]);
		if (val->mc - 1 < 0)
			temp = stack_b->head->nbr;
		else
			temp = val->med[val->mc - 1];
		while (stack_b->size && stack_b->tail->value >= temp)
		{
			ft_printf("%d\n", temp);
			if (stack_b->tail->value > temp)
			{
				interpreter(stack_a, stack_b, "rrb");
				interpreter(stack_a, stack_b, "pa");
			}
		}
		quicksort_ab(stack_a, stack_b, temp, val->quarter[val->mc] - 1);
		val->mc--;
	}
} */
