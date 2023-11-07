/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:04:57 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/07 21:11:45 by gfontao-         ###   ########.fr       */
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

	val->med = (max + min) / 2;
	val->quarter = (val->med + min) / 2;
}

void	quicksort_ab(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	t_node	*tail;
	t_val	val;
	int		big;

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
		while ((stack_a->head != tail && stack_b->head != tail && stack_b->tail != tail) || stack_a->head->value < val.med)
		{
			if (is_sorted(stack_a) || stack_a->head->value > max)
				break ;
			if (stack_a->head->value > val.med)
				interpreter(stack_a, stack_b, "ra");
			if (stack_a->head->value <= val.med)
			{
				interpreter(stack_a, stack_b, "pb");
				if (stack_b->head->value < val.quarter && stack_b->size > 1)
					interpreter(stack_a, stack_b, "rb");
			}
			big = get_big(stack_a)->value;
		}
		if (max != big)
			while (stack_a->tail->value != big)
				interpreter(stack_a, stack_b, "rra");
		min = get_small(stack_a)->value;
	}
	/*if (stack_b->size > 0)
		quicksort_ba(stack_a, stack_b, val.quarter);*/
	/*if (val.mc != -1)
		quicksort_ba(stack_a, stack_b, &val);*/
}

/*void	quicksort_ba(t_stack *stack_a, t_stack *stack_b, int quarter)
{
	int		max;
	int		min;
	t_node	*current;
	while (quarter > stack_b->head->value || stack_b->tail->value < quarter)
	{
		min = stack_b->head->value;
		max = stack_b->head->value;
		current = stack_b->head;
		while (current && current->value > stack_b->tail->value)
		{
			ft_printf("teste");
			if (current->value > max)
				max = current->value;
			if (current->value < min)
				min = current->value;
			current = current->next;
		}
		while (stack_b->head->value > stack_b->tail->value)
			interpreter(stack_a, stack_b, "pa");

	min = stack_b->head->value;
	max = stack_b->head->value;
	current = stack_b->head;
	while (current && current->value > stack_b->tail->value)
	{
		if (current->value > max)
			max = current->value;
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	while (stack_b->head->value > stack_b->tail->value)
		interpreter(stack_a, stack_b, "pa");
	if (!is_sorted(stack_a))
		quicksort_ab(stack_a, stack_b, min, max);
		min = stack_b->tail->value;
		max = stack_b->tail->value;
		current = stack_b->tail;
		while (current && stack_b->tail->value > stack_b->head->value)
		{
			if (current->value > max)
				max = current->value;
			if (current->value < min)
				min = current->value;
			current = current->prev;
		}
		while (stack_b->tail->value > stack_b->head->value)
		{
			interpreter(stack_a, stack_b, "rrb");
			interpreter(stack_a, stack_b, "pa");
		}
		quicksort_ab(stack_a, stack_b, min, max);
	}
	min = stack_b->head->value;
	max = stack_b->head->value;
	current = stack_b->head;
	while (current && stack_b->head->value > stack_b->tail->value)
	{
		if (current->value > max)
			max = current->value;
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	while (stack_b->size > 0)
		interpreter(stack_a, stack_b, "pa");
	quicksort_ab(stack_a, stack_b, min, max);
}*/

/* void	all_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;
	int		head;

	temp = stack_a->head;
	while (temp)
	{
		temp->cost.head = head_cost(stack_a, temp);
		temp->cost.tail = tail_cost(stack_a, temp);
		temp = temp->next;
	}
	temp = stack_b->head;
	while (temp)
	{
		temp->cost.head = head_cost(stack_b, temp);
		temp->cost.head = tail_cost(stack_b, temp);
		temp->cost.best = best_friend(stack_a, temp);
		temp = temp->next;
	}
}

t_node *best_friend(t_stack *stack_a, t_node *node)
{
	t_node	*temp;
	t_node	*best;

	temp = stack_a->head;
	best = temp;
	while (temp)
	{
		if (temp->value > node->value && temp->value < best->value)
			best = temp;
		temp = temp->next;
	}
	return (best);
}

t_node	*total_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*lowest;
	int head_cost;
	int tail_cost;
	int diff_cost;

	current = stack_b->head;
	lowest = current;
	while (current != NULL)
	{
		if (current->cost.head > current->cost.best->cost.head)
			head_cost = current->cost.head;
		else
			head_cost = current->cost.best->cost.head;
		if (current->cost.tail > current->cost.best->cost.tail)
			tail_cost = current->cost.tail;
		else
			tail_cost = current->cost.best->cost.tail;


		if (current->cost.head < current->cost.tail)
			diff_cost = current->cost.head;
		else
			diff_cost = current->cost.tail;
		if(current->cost.best->cost.head < current->cost.best->cost.tail)
			diff_cost += current->cost.best->cost.head;
		else
			diff_cost += current->cost.best->cost.tail;


		if (head_cost < diff_cost)
		{
				current->cost.direction = 'h';
				current->cost.total = head_cost;
		}
		else if(tail_cost < diff_cost)
		{
				current->cost.direction = 't';
				current->cost.total = tail_cost;
		}
		else
		{
			current->cost.direction = 'd';
			current->cost.total = diff_cost;
		}
		if (lowest->cost.total > current->cost.total)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*lowest;
	while (stack_b->size > 0)
	{
		lowest = total_cost(stack_a, stack_b);

	}

} */

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
