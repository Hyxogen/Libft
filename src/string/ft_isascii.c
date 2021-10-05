#include "../../include/libft.h"

int
	ft_isascii(int c)
{
	return (c >= LIBFT_ASCII_LOW && c <= LIBFT_ASCII_HIGH);
}
