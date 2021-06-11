#include "push_swap.h"

__int_b		b_swap(t_stack *stack)
{
	stack->value ^= stack->down->value;
	stack->down->value ^= stack->value;
	stack->value ^= stack->down->value;
	stack->order ^= stack->down->order;
	stack->down->order ^= stack->order;
	stack->order ^= stack->down->order;
	stack->chunk ^= stack->down->chunk;
	stack->down->chunk ^= stack->chunk;
	stack->chunk ^= stack->down->chunk;
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
	last->up = NULL;
	(*stack)->up = last;
	*stack = last;
	return (SUCCESS);
}

__int_b		b_push(t_stack **stack_from, t_stack **stack_into)
{
	int		ret;
	t_stack	*second_from;
	t_stack	*second_into;

	ret = 0;
	if (!*stack_from)
		return (ERROR_MALLOC);
	if (!*stack_into)
	{
		second_from = (*stack_from)->down;
		*stack_into = *stack_from;
		(*stack_into)->down = 0x000;
		*stack_from = second_from;
		(*stack_from)->up = 0x000;
		return (SUCCESS);
	}
	second_from = (*stack_from)->down;
	second_into = (*stack_into);
	(*stack_into) = *stack_from;
	(*stack_into)->down = second_into;
	second_into->up = (*stack_into);
	if (second_from)
	{
		(*stack_from) = second_from;
		(*stack_from)->up = 0x000;
	}
	else
		(*stack_from) = 0x000;
	return (SUCCESS);
}
