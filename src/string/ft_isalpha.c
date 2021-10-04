#include "../../include/libft.h"

int
	ft_isalpha(int c)
{
	return (c >= LIBFT_ALPHA_LOW && c <= LIBFT_ALPHA_HIGH);
}
