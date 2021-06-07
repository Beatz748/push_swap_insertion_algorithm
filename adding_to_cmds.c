#include "push_swap.h"

__int_b			add_command(t_commands **cmds, char *command)
{
	if (*cmds == NULL)
	{
		if (!(*cmds = (t_commands *)malloc(sizeof(t_commands))))
			return (ERROR_MALLOC);
		b_bzero(*cmds, sizeof(t_stack));
		(*cmds)->command = b_strdup(command);
		return (SUCCESS);
	}
	while ((*cmds)->next)
		(*cmds) = (*cmds)->next;
	if (!((*cmds)->next = (t_commands *)malloc(sizeof(t_commands))))
			return (ERROR_MALLOC);
	(*cmds)->command = b_strdup(command);
	return (SUCCESS);
}