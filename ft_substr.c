#include <stdlib.h>
#include "libft.h"

char
	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;

	if (!str || !len)
		return (0);
	while (start && *str)
	{
		str++;
		start--;
	}
	if (start && !*str)
		return (0);
	ret = malloc(len);
	ft_strlcpy(ret, str, len);
	return (ret);
}
