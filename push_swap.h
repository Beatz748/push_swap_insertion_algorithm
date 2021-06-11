#ifndef PUSH_SWAP
# define PUSH_SWAP
# define CHUNKS 40
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define SUCCESS				0
# define FAIL					1
# define ERROR_MALLOC			2
# define INVALID_ARG			3
# define ENTER_ARGUMENT			4
# define DUPLICATE_SYMBOLS		6
# define NOT_ENOUGH_ELEMENTS	7
# define ALREADY_SORTED			8

# define B_MAX_INT				2147483647
# define B_INT_MIN				-2147483648l
# define B_UINT64_MAX			18446744073709551615u
# define B_INT64_MAX			922337203685477580ul
# define B_INT64_MIN			-922337203685477580
# define MINUS					1
# define MINIMUM_NUM_ARGS		2

typedef unsigned long long		__uint64_b;
typedef long long int			__int64_b;
typedef int						__int_b;


typedef struct	s_stack
{
	__int64_b		value;
	__int64_b		order;
	__int_b			chunk;
	struct s_stack	*up;
	struct s_stack	*down;
}				t_stack;

typedef struct	s_commands
{
	char				*command;
	struct s_commands	*next;
}				t_commands;

typedef struct	s_base
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_commands		*cmds;
}				t_base;

/*-------------------------ADDING INFO-------------------------*/

__int_b		add_command(t_commands **cmds, char *command);
__int_b		check_for_sorted(t_stack *stack);
__int_b		add_number_to_stack(t_stack **stack, __int64_b num);
__int_b		argtoi(char **argv, t_base *base);
__int_b		sorting_two_three(t_base *base);
__int_b			get_count_nums(t_stack *stack);
__int_b		set_order(t_stack **stack);
__int_b		set_chunks(t_stack *stack, __int_b chunks_num);

/*----------------------------UTILS----------------------------*/

int			write_error(int ret);
void		b_print_stack(t_stack *stack);
char		*b_strdup(const char *src);
void		b_bzero(void *s, __uint64_b n);
__int64_b	b_atoll(const char *str);
t_stack		*get_last(t_stack *stack);

/*--------------------------COMMANDS---------------------------*/

__int_b		b_ra(t_stack **stack_a, t_commands **cmds);
__int_b		b_rb(t_stack **stack_a, t_commands **cmds);
__int_b		b_rrb(t_stack **stack_a, t_commands **cmds);
__int_b		b_rra(t_stack **stack_a, t_commands **cmds);
__int_b		b_pa(t_stack **stack_a, t_stack **stack_b, t_commands **cmds);
__int_b		b_pb(t_stack **stack_a, t_stack **stack_b, t_commands **cmds);
__int_b		b_sa(t_stack **stack_b, t_commands **cmds);
__int_b		b_sb(t_stack **stack_b, t_commands **cmds);

/*------------------------COMMANDS LOW-------------------------*/

__int_b		b_reverse_rotate(t_stack **stack);
__int_b		b_swap(t_stack *stack);
__int_b		b_push(t_stack **stack_from, t_stack **stack_into);
__int_b		b_rotate(t_stack **stack);

#endif
