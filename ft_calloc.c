#include <stdlib.h>

void	ft_bzero(void *dest, size_t len);

void
	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	ft_bzero(ret, count * size);
	return (ret);
}
