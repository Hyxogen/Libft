/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:52:36 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:07:18 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>

int
	get_num_size(long num)
{
	int	ret;

	ret = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		ret++;
		num *= 1;
	}
	while (num)
	{
		ret++;
		num /= 10;
	}
	return (ret);
}

char
	*ft_itoa(int num)
{
	long	long_num;
	int		num_size;
	char	*ret;

	long_num = num;
	num_size = get_num_size(num);
	ret = malloc(num_size + 1);
	if (!ret)
		return (0);
	ret[num_size] = '\0';
	if (long_num < 0)
	{
		long_num *= -1;
		ret[0] = '-';
	}
	while (1)
	{
		ret[num_size - 1] = '0' + (long_num % 10);
		long_num /= 10;
		num_size--;
		if (!long_num)
			break ;
	}
	return (ret);
}
