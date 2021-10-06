#include <wchar.h>

size_t	ft_strlen(const char *str);

size_t
	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t srclen;
	size_t len;

	srclen = ft_strlen(src);	
	if (!dstsize || !srclen)
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
