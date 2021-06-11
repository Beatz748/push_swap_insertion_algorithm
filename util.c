#include "push_swap.h"

t_stack			*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->down)
		stack = stack->down;
	return (stack);
}

void		b_bzero(void *s, __uint64_b n)
{
	__uint64_b	i = 0;

	while (++i <= n && s)
	{
		*(char *)s = 0x000;
		++s;
	}
}

char	*b_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0x000;
	return (dest);
}

__int64_b	b_atoll(const char *str)
{
	__int64_b	i;
	int			minus;
	__int64_b	number;

	number = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == 0x02d)
		minus = -1;
	if (str[i] == 0x02b || str[i] == 0x02d)
		i++;
	while (str[i] >= 0x030 && str[i] <= 0x039)
	{
		if (number < 9223372036854775807)
			number = number * 10 + str[i++] - 0x030;
		if (number > 9223372036854775807 && minus < 0)
			return (SUCCESS);
		else if (number > 9223372036854775807)
			return (-1);
	}
	return ((int)(number * minus));
}
