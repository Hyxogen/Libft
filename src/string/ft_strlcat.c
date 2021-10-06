#include <wchar.h>

size_t	ft_strlen(const char *str);

size_t
	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (!dstsize || dstlen > dstsize)
		return (dstlen + srclen);
	while (*dst) {
		dst++;
		dstsize--;
		if (!dstsize)
			break ;
	}
	if (!dstsize)
		return (dstlen + srclen);
	while (dstsize - 1)
	{
		*dst = *src;
		src++;
		dst++;
		dstsize--;
	}
	*dst = '\0';
	return (dstlen + srclen);
}
