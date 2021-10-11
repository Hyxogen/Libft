#include <unistd.h>
#include "libft.h"

static void
	ft_putnbr_fd_r(long num, int fd)
{
	if (num)
	{
		ft_putnbr_fd_r(num / 10, fd);
		ft_putchar_fd('0' + (num % 10), fd);
	}
}

void
	ft_putnbr_fd(int num, int fd)
{
	long	long_num;

	long_num = num;
	if (long_num < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_r(long_num * -1, fd);
	}
	else
		ft_putnbr_fd_r(long_num, fd);
}
