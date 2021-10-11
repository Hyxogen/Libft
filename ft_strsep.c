#include "libft.h"

char
	*ft_strsep(char **stringp, const char *delim)
{
	char	*copy;
	char	*delim_pos;

	copy = *stringp;
	delim_pos = ft_strchrset(*stringp, delim);
	if (delim_pos)
	{
		*delim_pos = '\0';
		*stringp = delim_pos + 1;
	}
	else
		*stringp = 0;
	return (copy);
}
