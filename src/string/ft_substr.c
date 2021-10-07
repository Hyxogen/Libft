#include <stdlib.h>
#include "../../include/libft.h"

char
	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;
	size_t	str_len;

	while (start && *str)
	{
		str++;
		start--;
	}
	if (start && !*str)
		return (0);
	str_len = ft_strlen(str);
	ret = malloc(len);
	ft_strlcpy(ret, str, len);
	return (ret);
}
