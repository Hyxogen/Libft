#include <wchar.h>

void
	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*dest_arr;
	const char	*src_arr;

	if ((dest == src) || !len)
		return (dest);
	dest_arr = dest;
	src_arr = src;
	while (len)
	{
		*dest_arr = *src_arr;
		dest_arr++;
		src_arr++;
		len--;
	}
	return (dest);
}
