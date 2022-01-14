#include <ft_math.h>

int
	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

long
	ft_lmin(long a, long b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t
	ft_stmin(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
