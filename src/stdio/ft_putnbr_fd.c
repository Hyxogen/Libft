/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:58:20 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 15:02:07 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_stdio.h>

size_t
	put_nbr_base_signed(int fd, long number,
	const char *baseStr, int base)
{
	size_t	ret;

	ret = 0;
	if (number < 0)
	{
		ret += ft_putchar_fd(fd, '-');
		number *= -1;
	}
	if (number / base)
		ret += put_nbr_base_signed(fd, number / base, baseStr, base);
	ret += ft_putchar_fd(fd, baseStr[number % base]);
	return (ret);
}

size_t
	put_nbr_base_unsigned(int fd, unsigned long number,
	const char *baseStr, int base)
{
	size_t	ret;

	ret = 0;
	if (number / base)
		ret += put_nbr_base_unsigned(fd, number / base, baseStr, base);
	ret += ft_putchar_fd(fd, baseStr[number % base]);
	return (ret);
}

size_t
	ft_putnbr_fd(int fd, int num)
{
	return (put_nbr_base_signed(fd, num, "0123456789", 10));
}
