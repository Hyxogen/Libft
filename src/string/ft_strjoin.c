#include "../../include/libft.h"

char
	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	ft_memcpy(ret, s1, s1_len);	
	ft_memcpy(ret + s1_len, s2, s2_len + 1);
	return (ret);	
}