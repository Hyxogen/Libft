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
	clear_array(char **array)
{
	char	**start;

	start = array;
	while (*array)
	{
		free(*array);
		array++;
	}
	free (start);
}

static int
	fill_array(char **out, char *dup, const char *delim)
{
	char	*token_start;

	while (1)
	{
		token_start = ft_strsep(&dup, delim);
		if (token_start == dup)
			continue ;
		if (!dup && *token_start)
		{
			*out = ft_strdup(token_start);
			if (!*out)
				return (0);
			break ;
		}
		else if (!dup)
			break ;
		else if (dup - token_start > 1)
		{
			*out = ft_strdup(token_start);
			if (!*out)
				return (0);
			out++;
		}
	}
	return (1);
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
	char	*dup;
	size_t	size;

	delim[0] = c;
	delim[1] = '\0';
	size = get_size(str, c);
	if (!size)
		return (0);
	ret = malloc(sizeof(char *) * size);
	if (!ret)
		return (0);
	ft_bzero(ret, sizeof(char *) * size);
	dup = ft_strdup(str);
	if (!dup)
		return (0);
	if (!fill_array(ret, dup, delim))
	{
		clear_array(ret);
		free(dup);
		return (0);
	}
	free(dup);
	return (ret);
}
