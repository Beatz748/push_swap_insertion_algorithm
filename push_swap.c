#include "push_swap.h"

t_stack  *uk;

void print()
{
	b_print_stack(uk);
}

__int_b			insertion_sort(t_base *base)
{
	// b_ra(&base->stack_a, &base->cmds);
	// b_print_stack(base->stack_a);
	return (SUCCESS);
}

int 			main(int argc, char **argv)
{
	atexit(print);
	int		ret;
	t_base	*base;

	if (!(base = (t_base *)malloc(sizeof(t_base))))
		return (write_error(ERROR_MALLOC));
	base->stack_a = NULL;
	base->stack_b = NULL;
	if (argc < MINIMUM_NUM_ARGS)
		return (write_error(ENTER_ARGUMENT));
	if (!!(ret = argtoi(++argv, base)))
		return (write_error(ret));
	uk = base->stack_a;
	if (!!(ret = insertion_sort(base)))
		return (write_error(ret));
	return (SUCCESS);
}
