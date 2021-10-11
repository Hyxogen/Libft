#include <wchar.h>

size_t	ft_strlen(const char *str);

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
