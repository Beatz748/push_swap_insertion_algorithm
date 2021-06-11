#include "push_swap.h"

t_stack  **uk;
t_commands **uk2;
void	print_commands(t_commands *cmds)
{
	while (cmds)
	{
		printf("%s\n", cmds->command);
		cmds = cmds->next;
	}
}

void print()
{
	b_print_stack(*uk);
	print_commands(*uk2);
}

__int_b			is_there_current_chunk(t_stack *stack, __int_b chunk)
{
	while (stack)
	{
		if (stack->chunk == chunk)
			return (chunk);
		stack = stack->down;
	}
	return (++chunk);
}

__int_b			print_all(t_base *base)
{
	t_stack		*A;
	t_stack		*B;

	A = base->stack_a;
	B = base->stack_b;
	printf("Stack A    Stack B\n");
	while (A || B)
	{
			printf("|");
			if (A)
			{
				printf("%5lld", A->value);
				A = A->down;
			}
			else
				printf("%5c", ' ');
			printf("| ");
			printf("   |");
			if (B)
			{
				printf("%5lld", B->value);
				B = B->down;
			}
			else
				printf("%5c", ' ');
			printf("|");
		printf("\n");
	}
	return (SUCCESS);
}

__int_b			push_to_top_a(t_stack **stack, __int_b current_chunk, t_commands **cmds)
{
	t_stack	*tmp;
	__int_b	count_first;
	__int_b	count_second;

	count_first = 0;
	count_second = 1;
	tmp = *stack;
	while (tmp && tmp->chunk != current_chunk)
	{
		tmp = tmp->down;
		++count_first;
	}
	tmp = get_last(*stack);
	while (tmp && tmp->chunk != current_chunk)
	{
		tmp = tmp->up;
		++count_second;
	}
	if (count_second > count_first)
		while (count_first--)
			b_ra(stack, cmds);
	else
		while (count_second--)
			b_rra(stack, cmds);
	return (SUCCESS);
}

__int_b			is_all_sorted(t_stack *stack)
{
	t_stack		*tmp;

	if (!stack || !stack->down)
		return (0);
	tmp = stack;
	while (tmp->down && tmp->value > tmp->down->value)
		tmp = tmp->down;
	if (!tmp->down)
		return (0);
	return (1);
}

__int_b			is_sorted_chunk(t_stack *stack)
{
	__int_b		chunk;
	t_stack		*tmp;

	if (!stack || !stack->down)
		return (0);
	tmp = stack;
	chunk = stack->chunk;
	while (tmp->down && tmp->down->chunk == chunk && tmp->value > tmp->down->value)
		tmp = tmp->down;
	if (!tmp->down || tmp->down->chunk != chunk)
		return (0);
	return (1);
}
__int64_b			all_low_or_high(t_stack *stack, __int_b a)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp && tmp->value > a)
		tmp = tmp->down;
	if (!tmp)
		return (0);
	tmp = stack;
	while (tmp && tmp->value < a)
		tmp = tmp->down;
	if (!tmp)
		return (0);
	return (1);
}

__int_b			find_near_order(t_stack *stack, __int_b target)
{
	__int64_b	ret;
	__int64_b	tmp;
	__int64_b	chunk;
	__int64_b	safe;

	chunk = stack->chunk;
	ret = B_INT64_MIN;
	safe = 1;
	while (stack)
	{
		if (stack->order > ret && stack->order < target)
			ret = stack->order;
		stack = stack->down;
	}
	return (ret);
}

__int_b			paste_near(t_stack **stack, t_commands **cmds, __int_b near)
{
	t_stack	*tmp;
	__int_b	count_first;
	__int_b	count_second;

	count_first = 0;
	count_second = 1;
	tmp = *stack;
	while (tmp && tmp->order != near)
	{
		tmp = tmp->down;
		++count_first;
	}
	tmp = get_last(*stack);
	while (tmp && tmp->order != near)
	{
		tmp = tmp->up;
		++count_second;
	}
	if (count_second > count_first)
		while (count_first--)
			b_rb(stack, cmds);
	else
		while (count_second--)
			b_rrb(stack, cmds);
	return (SUCCESS);
}

__int_b			how_many_in_chunk(t_stack *stack)
{
	__int_b	current;
	__int_b	ret;

	ret = 0;
	current = stack->chunk;
	while (stack && stack->chunk == current)
	{
		stack = stack->down;
		++ret;
	}
	return (ret);
}

__int_b			make_sorted(t_stack *stack)
{
	__int_b		first_;
	__int_b		nums_in_chunk;
	t_stack		*tmp;
	__int_b		current_chunk;
	__int_b		max;

	max = stack->order;
	current_chunk = stack->chunk;
	tmp = stack;
	first_ = 0;
	nums_in_chunk = how_many_in_chunk(tmp);
	while (tmp && tmp->chunk == current_chunk)
	{
		if (max < tmp->order)
			break;
		++first_;
		tmp = tmp->down;
	}
	if ((nums_in_chunk / 2) > first_)
		return (1);
	return (0);
}

__int_b			prepare_stack_b(t_base *base)
{
	__int_b		a;
	__int64_b	near;

	a = base->stack_a->value;
	if (!base->stack_b || !base->stack_b->down)
		return (SUCCESS);
	near = find_near_order(base->stack_b, base->stack_a->order);
	if (all_low_or_high(base->stack_b, a))
		while (base->stack_b->order != near)
		{
			paste_near(&base->stack_b, &base->cmds, near);
		// print_all(base);
		}
	else
		while (is_all_sorted(base->stack_b))
		{
			if (make_sorted(base->stack_b))
				b_rb(&base->stack_b, &base->cmds);
			else
				b_rrb(&base->stack_b, &base->cmds);
			// print_all(base);
		}

	return (SUCCESS);
}


__int_b			sorting(t_base *base)
{
	__int_b		ret;
	t_stack		*target;
	__int_b		current_chunk;

	current_chunk = 0;
	while (base->stack_a)
	{
		if ((ret = push_to_top_a(&base->stack_a, current_chunk, &base->cmds)))
			return (FAIL);
		prepare_stack_b(base);
		b_pb(&base->stack_a, &base->stack_b, &base->cmds);
		current_chunk = is_there_current_chunk(base->stack_a, current_chunk);
		// print_all(base);
	}
		while (is_sorted_chunk(base->stack_b))
		{
			if (make_sorted(base->stack_b))
				b_rb(&base->stack_b, &base->cmds);
			else
				b_rrb(&base->stack_b, &base->cmds);
			print_all(base);
		}
	while (is_all_sorted(base->stack_b))
			b_rb(&base->stack_b, &base->cmds);
	__int_b	c = get_count_nums(base->stack_b);
	while (c--)
		b_pa(&base->stack_a, &base->stack_b, &base->cmds);
	// print_all(base);
	return (SUCCESS);
}

__int_b			insertion_sort(t_base *base, int count_nums)
{
	int	ret;

	if ((ret = set_order(&base->stack_a)))
		return (ret);
	if ((ret = set_chunks(base->stack_a, CHUNKS)))
		return (ret);
	else if (count_nums == 2 || count_nums == 3)
		return (sorting_two_three(base));
	else if (count_nums > 3)
		return (sorting(base));
	return (SUCCESS);
}

int 			main(int argc, char **argv)
{
	// atexit(print);
	int		ret;
	t_base	*base;

	if (!(base = (t_base *)malloc(sizeof(t_base))))
		return (write_error(ERROR_MALLOC));
	base->stack_a = NULL;
	base->stack_b = NULL;
	base->cmds = NULL;
	uk = &base->stack_a;
	uk2 = &base->cmds;
	if (argc < MINIMUM_NUM_ARGS)
		return (write_error(ENTER_ARGUMENT));
	if (!!(ret = argtoi(++argv, base)))
		return (write_error(ret));
	if (!!(ret = check_for_sorted(base->stack_a)))
		return (write_error(ret));
	if (!!(ret = insertion_sort(base, argc - 1)))
		return (write_error(ret));
	print_commands(base->cmds);
	return (SUCCESS);
}
