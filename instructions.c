#include "push_swap.h"

__int_b		b_swap(t_stack *stack)
{
	stack->value ^= stack->down->value;
	stack->down->value ^= stack->value;
	stack->value ^= stack->down->value;
	return (SUCCESS);
}

__int_b		b_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second;

	if (!*stack || !(*stack)->down)
		return (FAIL);
	last = *stack;
	second = (*stack)->down;
	while (last->down)
		last = last->down;
	last->down = *stack;
	(*stack)->up = last;
	(*stack)->down =0x000;
	second->up = 0x000;
	*stack = second;
	return (SUCCESS);
}

__int_b		b_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!*stack || !(*stack)->down)
		return (FAIL);
	last = *stack;
	while (last->down)
		last = last->down;
	last->down = *stack;
	prev_last = last->up;
	prev_last->down= 0x000;
	last->up = 0x000;
	*stack = last;
	return (SUCCESS);
}

__int_b		b_push(t_stack **stack_from, t_stack **stack_into)
{
	int		ret;
	t_stack	*second;

	ret = 0;
	second = (*stack_from)->down;
	if (!*stack_from)
		return (ERROR_MALLOC);
	if ((ret = add_number_to_stack(stack_into, (*stack_from)->value)))
		return (ret);
	b_reverse_rotate(stack_into);
	second->up = 0x000;
	*stack_from = second;
	return (SUCCESS);
}
