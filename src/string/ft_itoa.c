#include "../../include/libft.h"

static void
	ft_itoa_r(char *str, long num, int pos)
{
	if (pos)
	{
		ft_itoa_r(str, num / 10, pos - 1);
		str[pos - 1] = '0' + (num % 10);
	}
}

static int
	get_length(long num)
{
	if (num < 0)
		return (get_length(-1 * (num / 10)) + 2);
	else if (num)
		return (get_length(num / 10) + 1);
	else
		return (1);
}

char
	*ft_itoa(int num)
{
	long	long_num;
	int		length;
	char	*ret;

	long_num = num;
	length = get_length(long_num);
	ret = malloc(length + 1);
	if (long_num < 0)
	{
		*ret = '-';
		ft_itoa_r(ret + 1, long_num * -1, length - 2);
	}
	else if (long_num > 0)
		ft_itoa_r(ret, long_num, length - 1);
	else
		ret[0] = '0';
	ret[length] = '\0';
	return (ret);
}
