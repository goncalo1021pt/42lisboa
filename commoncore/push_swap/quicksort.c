#include "includes/push_swap.h"

int	medium(t_stack stack, t_node *high)
{
	int	max;
	int	min;

	max = stack.head->value;
	min = stack.head->value;
	while (stack.head != high)
	{
		if (max < stack.head->value)
			max = stack.head->value;
		if (min > stack.head->value)
			min = stack.head->value;
		stack.head = stack.head->next;
	}
	return ((max + min) / 2);
}

void	quick_sort(t_stack stack_a, t_stack stack_b)
{
	t_node	*pivot;
	

	pivot = find_node(stack_a, medium(stack_a, stack_a.tail));
	while (stack_a.head != pivot)
		ft_rev_rotate(&stack_a);
	ft_push(&stack_a, &stack_b);
	while (stack_a.head)
	{
		/* code */
	}
	
}