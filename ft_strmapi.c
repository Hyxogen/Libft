#include "libft.h"

char
	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	unsigned int	index;
	char			*copy;
	char			*ret;

	copy = ft_strdup(str);
	if (!copy)
		return (0);
	ret = copy;
	index = 0;
	while (*copy)
	{
		*copy = func(index, *copy);
		index++;
		copy++;
	}
	return (ret);
}
