/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:09:15 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 12:06:15 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <ft_string.h>

size_t
	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	len;

	srclen = ft_strlen(src);
	if (!dstsize)
		return (srclen);
	if (srclen >= dstsize)
		len = dstsize - 1;
	else
		len = srclen;
	while (len)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	*dst = '\0';
	return (srclen);
}
