#include <stdio.h>
#include "../../include/libft.h"

int
	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
