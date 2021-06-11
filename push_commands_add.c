#include "push_swap.h"

__int_b			b_pa(t_stack **stack_a, t_stack **stack_b, t_commands **cmds)
{
	b_push(stack_b, stack_a);
	add_command(cmds, "pa");
	return (SUCCESS);
}

__int_b			b_pb(t_stack **stack_a, t_stack **stack_b, t_commands **cmds)
{
	b_push(stack_a, stack_b);
	add_command(cmds, "pb");
	return (SUCCESS);
}
