#include <stdlib.h>
#include "libft.h"

char
	*ft_strtrim(char const *str, char const *set)
{
	char	*ret;
	size_t	str_len;
	size_t	new_len;
	t_bool	trim_start;
	t_bool	trim_end;
	
	str_len = ft_strlen(str);
	trim_start = ft_strchrset(str, set) == str;
	trim_end = ft_strrchrset(str, set) == (str + str_len - 1);
	new_len = str_len - trim_start - trim_end;
	ret = malloc(new_len + 1);
	ft_strlcpy(ret, str + trim_start, new_len + 1);
	return (ret);
}
