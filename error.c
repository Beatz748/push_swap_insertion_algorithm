#include "push_swap.h"

char		*b_stpncpy(char *dst, const char *src, size_t len)
{
	int		i = -1;

	while (++i < len && src[i])
		dst[i] = src[i];
	while (dst[i])
	{
		dst[i] = 0;
		++i;
	}
	return (dst);
}

int			write_error(int ret)
{
	char	buf[50];
	size_t	length = 18;

	b_bzero((void *)buf, 50);

	b_stpncpy(buf, "ERROR\n PROBLEM --", 18);

	{
		if ((ret == FAIL) && (length += 23))
			b_stpncpy(buf + 18, " SOMETHING WENT WRONG\n", 23);
		else if ((ret == ERROR_MALLOC) && (length += 12))
			b_stpncpy(buf + 18, " MALLOC IS BROKEN\n", 12);
		else if ((ret == INVALID_ARG) && (length += 23))
			b_stpncpy(buf + 18, " ONLY NUMERIC ARGS !!\n", 23);
		else if ((ret == ENTER_ARGUMENT) && (length += 20))
			b_stpncpy(buf + 18, " ARGUMENTS ARE BAD\n", 20);
		else if ((ret == DUPLICATE_SYMBOLS) && (length += 20))
			b_stpncpy(buf + 18, " DUPLICATE SYMBOLS\n", 20);
		else if ((ret == NOT_ENOUGH_ELEMENTS) && (length += 22))
			b_stpncpy(buf + 18, " NOT_ENOUGH_ELEMENTS\n", 22);
		else if ((ret == ALREADY_SORTED) && (length += 17))
			b_stpncpy(buf + 18, " ALREADY SORTED\n", 17);

	}

	if (write(STDERR_FILENO, buf, length) != length)
		return (FAIL);
	return (ret);
}
