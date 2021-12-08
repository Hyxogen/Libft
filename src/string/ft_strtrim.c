/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:10:21 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:13:53 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>
#include <ft_stdbool.h>

static ft_bool
	is_in(char c, const char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (TRUE);
		charset++;
	}
	return (FALSE);
}

static const char
	*ft_strtrim_r(const char *str, const char *const charset, size_t *str_len)
{
	const char	*end;
	const char	*begin;

	while (*str && is_in(*str, charset))
		str++;
	if (!*str)
	{
		*str_len = 0;
		return (str);
	}
	begin = str;
	while (*str)
	{
		if (!is_in(*str, charset))
			end = str;
		str++;
	}
	*str_len = end - begin + 1;
	return (begin);
}

char
	*ft_strtrim(char const *str, char const *charset)
{
	const char	*trimmed_string;
	char		*ret;
	size_t		str_len;

	str_len = ft_strlen(str);
	trimmed_string = ft_strtrim_r(str, charset, &str_len);
	ret = malloc(str_len + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, trimmed_string, str_len + 1);
	return (ret);
}
