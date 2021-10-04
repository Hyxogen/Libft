#include "../../include/libft.h"

int
	ft_isdigit(int c)
{
	return (c >= LIBFT_DIGIT_LOW && c <= LIBFT_DIGIT_HIGH);
}
