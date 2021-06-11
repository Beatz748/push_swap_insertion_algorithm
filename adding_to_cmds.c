#include "push_swap.h"

__int_b			add_command(t_commands **cmds, char *command)
{
	t_commands	*first;

	first = *cmds;
	if (*cmds == NULL)
	{
		if (!(*cmds = (t_commands *)malloc(sizeof(t_commands))))
			return (ERROR_MALLOC);
		b_bzero(*cmds, sizeof(t_commands));
		(*cmds)->command = b_strdup(command);
		return (SUCCESS);
	}
	while ((*cmds)->next)
		(*cmds) = (*cmds)->next;
	if (!((*cmds)->next = (t_commands *)malloc(sizeof(t_commands))))
			return (ERROR_MALLOC);
	(*cmds)->next->command = b_strdup(command);
	(*cmds)->next->next = 0x000;
	(*cmds) = first;
	return (SUCCESS);
}
