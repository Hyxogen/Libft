/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:09:07 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:09:12 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

size_t	ft_strlen(const char *str);

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	len;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (!dstsize || dstlen > dstsize)
		return (dstsize + srclen);
	if (srclen >= (dstsize - dstlen))
		len = dstsize - dstlen - 1;
	else
		len = srclen;
	while (*dst)
	{
		dst++;
		dstsize--;
		if (!dstsize)
			return (dstlen + srclen);
	}
	ft_strlcpy(dst, src, len + 1);
	return (dstlen + srclen);
}
