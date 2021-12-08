/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:09:42 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:09:47 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *) haystack);
	while ((len >= needle_len) && *haystack)
	{
		if (!ft_memcmp(haystack, needle, needle_len))
			return ((char *) haystack);
		len--;
		haystack++;
	}
	return (0);
}
