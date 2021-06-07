#include "push_swap.h"

__int_b			b_ra(t_stack **stack_a, t_commands **cmds)
{
	b_rotate(stack_a);
	add_command(cmds, "ra");
	return (SUCCESS);
}

__int_b			b_rb(t_stack **stack_b, t_commands **cmds)
{
	b_rotate(stack_b);
	add_command(cmds, "rb");
	return (SUCCESS);
}

__int_b			b_rra(t_stack **stack_a, t_commands **cmds)
{
	b_reverse_rotate(stack_a);
	add_command(cmds, "rra");
	return (SUCCESS);
}

__int_b			b_rrb(t_stack **stack_b, t_commands **cmds)
{
	b_reverse_rotate(stack_b);
	add_command(cmds, "rrb");
	return (SUCCESS);
}