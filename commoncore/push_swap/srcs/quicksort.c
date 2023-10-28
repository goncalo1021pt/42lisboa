/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:04:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/28 13:03:12 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	send_pivot(t_stack *src, t_stack *dest, t_node *pivot)
{
	if (head_cost(src, pivot) < tail_cost(src, pivot))
	{
		while (src->head != pivot)
			ft_rotate(src);
		ft_push(src, dest);
	}
	else
	{
		while (src->head != pivot)
			ft_rev_rotate(src);
		ft_push(src, dest);
	}
}

void	restore(t_stack *stack, t_node *top)
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
}

t_stack *find_stack(t_stack *stack_a, t_stack *stack_b, t_node *find)
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

/* void	recursive_quicksort(t_node *low, t_node *high, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*pivot;
	t_stack	*current;

	current = find_stack(stack_a, stack_b, low);
	pivot = find_node(*stack_a, medium(stack_a->head, stack_a->tail));
} */

void	quicksort_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tail;
	int		med;
	int		quarter;

	while (!is_sorted(stack_a))
	{
		med = medium(stack_a->head, stack_a->tail, &quarter);
		tail = stack_a->tail;
		while (stack_a->head != tail || stack_a->head->value <= med)
		{
			if (is_sorted(stack_a))
				break ;
			if (stack_a->head->value > med)
				ft_rotate(stack_a);
			if (stack_a->head->value <= med)
			{
				ft_push(stack_a, stack_b);
				if (stack_b->head->value <= quarter && stack_b->head->next && stack_b->head->next->value > quarter)
					ft_rotate(stack_b);
			}
		}
	}	
}

/* void quicksort_ba(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->head != NULL)
	{
		
	}
	
} */

/* 		if (stack_a->head == tail)
		{
			if (stack_a->head->value <= med)
				ft_push(stack_a, stack_b);
			break ;
		}
 */