#include "libft.h"

static size_t
	get_size(const char *str, char c)
{
	if (!*str)
		return (1);
	while (*str && *str == c)
		str++;
	while (*str && *str != c)
		str++;
	return (get_size(str, c) + 1);
}

static void
	fill_array(char **out, const char *str, const char *delim)
{
	char	*dup;
	char	*token_start;

	dup = ft_strdup(str);
	while (1)
	{
		token_start = ft_strsep(&dup, delim);
		if (token_start == dup)
			continue;
		if (!dup && *token_start)
		{
			*out = token_start;
			*(out + 1) = 0;
			break;
		}
		else if (!dup)
		{
			*out = 0;
			break ;
		}
		else if (dup - token_start > 1)
		{
			*out = token_start;
			out++;
		}
	}
}

/*
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must be
ended by a NULL pointer.
*/
char
	**ft_split(char const *str, char c)
{
	char	delim[2];
	char	**ret;
	size_t	size;

	delim[0] = c;
	delim[1] = '\0';
	size = get_size(str, c);
	if (!size)
		return (0);
	ret = malloc(sizeof(char *) * size);
	if (!ret)
		return (0);
	fill_array(ret, str, delim);
	return (ret);
}
