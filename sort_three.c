#include "push_swap.h"

__int_b			sorting_two_three(t_base *base)
{
	__int_b	ret;
	t_stack	*last;
	t_stack	**stack;

	stack = &base->stack_a;
	last = get_last(*stack);
	if ((*stack)->value > last->value)
		b_ra(&(base->stack_a), &(base->cmds));
	last = get_last(*stack);
	if ((*stack)->value > (*stack)->down->value)
		b_sa(&(base->stack_a), &(base->cmds));
	last = get_last(*stack);
	if ((*stack)->down->value > last->value)
	{
		b_sa(&(base->stack_a), &(base->cmds));
		b_ra(&(base->stack_a), &(base->cmds));
	}
	return (SUCCESS);
}
