#include "libft.h"

void
	ft_striteri(char *str, void (*func)(unsigned int, char*))
{
	int	index;

	index = 0;
	while (*str)
	{
		func(index, str);
		index++;
		str++;
	}
}
