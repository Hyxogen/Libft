#include "../../include/libft.h"

static char
	*ft_itoa_r(int num, int pos)
{
	long	val;

	val = num;
	if (val < 0)
	{
		val *= -1;
		pos += 1;
	}
	ft_itoa(num / 10, pos + 1);
}

char
	*ft_itoa(int n)
{
	long	val;

	val = n;

}