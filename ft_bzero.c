#include <wchar.h>

void	*ft_memset(void *dest, int ch, size_t len);

void
	ft_bzero(void *dest, size_t len)
{
	ft_memset(dest, 0, len);
}
