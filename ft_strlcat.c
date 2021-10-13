#include <wchar.h>

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
			break ;
	}
	if (!dstsize)
		return (dstlen + srclen);
	while (len)
	{
		*dst = *src;
		src++;
		dst++;
		len--;
	}
	*dst = '\0';
	return (dstlen + srclen);
}
