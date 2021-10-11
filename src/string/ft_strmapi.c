#include "../../include/libft.h"

char
	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	char						*copy;
	char						*ret;
	unsigned int		index;

	copy = ft_strdup(str);
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
