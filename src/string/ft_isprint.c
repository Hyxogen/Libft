#include "../../include/libft.h"

int
	isprint(int c)
{
	return (c >= LIBFT_PRINTABLE_LOW && c <= LIBFT_PRINTABLE_HIGH);
}
