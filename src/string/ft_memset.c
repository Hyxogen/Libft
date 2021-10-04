#include <string.h>

void
	*ft_memset(void *dest, int ch, size_t len)
{
	unsigned char	*array;

	if (!dest || !len)
		return (dest);
	array = dest;

	while(len)
	{
		*array = (unsigned char) ch;
		len--;
		array++;
	}
	return (dest);
}
