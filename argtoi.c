#include "push_swap.h"

void			b_print_stack(t_stack *stack)
{
	__int_b		i;

	i = -1;
	while (stack)
	{
		printf("order -- %d : value : %lld \n", ++i, stack->value);
		stack = stack->down;
	}
}

// __int_b			add_command(t_commands **cmds, char *str)
// {
// 	if (*cmds == NULL)
// 	{
// 		if (!(*cmds = (t_stack *)malloc(sizeof(t_stack))))
// 			return (ERROR_MALLOC);
// 		b_bzero(*cmds, sizeof(t_stack));
// 		(*cmds)->value = num;
// 		return (SUCCESS);
// 	}
// 	while ((*cmds)->down)
// 		(*cmds) = (*cmds)->down;
// 	if (!((*scmds)->down->up = *stack;
// 	(*cmds) = (*cmds)->down;
// 	(*cmds)->command = num;
// 	return (SUCCESS);
// }

__int_b			add_number_to_stack(t_stack **stack, __int64_b num)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack == NULL)
	{
		if (!(*stack = (t_stack *)malloc(sizeof(t_stack))))
			return (ERROR_MALLOC);
		b_bzero(*stack, sizeof(t_stack));
		(*stack)->value = num;
		return (SUCCESS);
	}
	while ((*stack)->down)
	{
		if ((*stack)->value == num)
			return (DUPLICATE_SYMBOLS);
		(*stack) = (*stack)->down;
	}
	if (!((*stack)->down = (t_stack *)malloc(sizeof(t_stack))))
			return (ERROR_MALLOC);
	(*stack)->down->up = *stack;
	(*stack) = (*stack)->down;
	(*stack)->value = num;
	*stack = tmp;
	return (SUCCESS);
}

__int_b			argtoi(char **argv, t_base *base)
{
	__int64_b	num;
	__int_b	flag;

	while (*argv)
	{
		num = 0;
		flag = 1;
		while (((flag) && **argv == '-' && ++(*argv) && !(flag = 0)) || (**argv >= 0x030 && **argv <= 0x039))
		{
			if (num > B_INT64_MAX)
				return (INVALID_ARG);
			num = num * 10 + **argv - 0x030;
			++(*argv);
		}
		if (**argv)
			return (INVALID_ARG);
		if (flag == 0)
			num = ~(num - MINUS);
		if ((flag = add_number_to_stack(&base->stack_a, num)))
			return (flag);
		++argv;
	}
	return (SUCCESS);
}
