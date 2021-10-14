#include <stdlib.h>
#include "libft.h"

char
	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;

	while (start && *str)
	{
		str++;
		start--;
	}
	ret = malloc(len + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, str, len + 1);
	return (ret);
}
