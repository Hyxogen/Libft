#include <stdlib.h>
#include "libft.h"

char
	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc(s1_len + s2_len + 1);
	if (!ret)
			return (0);
	ft_memcpy(ret, s1, s1_len);
	ft_memcpy(ret + s1_len, s2, s2_len + 1);
	return (ret);
}
