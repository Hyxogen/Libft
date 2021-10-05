#include <wchar.h>

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n);

/*
len 3

110 	(src)
110	 	(dest (src))

110 	(src)
0110 	(dest (src+1))

110 	(src)
00100	(dest (src+2))

110 	(src)
000100	(dest (src+3))

110 	(src)
110	 	(dest (src))

000110 	(src)
001100	(dest (src-1))

000110 	(src)
011000	(dest (src-2))

000110 	(src)
110000	(dest (src-3))
*/

//Expects that dest and src and len are all not equal to zero
static void
	*ft_memcpy_backward(void *dest, const void *src, size_t len)
{
	char		*dest_arr;
	const char	*src_arr;

	dest_arr = dest + len - 1;
	src_arr = src + len - 1;
	while (len)
	{
		*dest_arr = *src_arr;
		dest_arr--;
		src_arr--;
		len--;
	}
	return (dest);
}

//Expects that dest and src and len are all not equal to zero
static void
	*ft_memcpy_forward(void *dest, const void *src, size_t len)
{
	char		*dest_arr;
	const char	*src_arr;

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

void
	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dest_arr;
	const char	*src_arr;

	if (!dest || !src || !len)
		return (dest);
	dest_arr = dest;
	src_arr = src;
	if (dest_arr >= src_arr && dest_arr < src_arr + len)
		return (ft_memcpy_backward(dest, src, len));
	else if (dest_arr < src_arr && dest_arr > src_arr - len)
		return (ft_memcpy_forward(dest, src, len));
	return (ft_memcpy(dest, src, len));
}
