#include "libft.h"

int
	ft_isprint(int c)
{
	return (c >= LIBFT_PRINTABLE_LOW && c <= LIBFT_PRINTABLE_HIGH);
}
