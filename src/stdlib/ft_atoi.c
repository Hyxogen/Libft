/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:50:59 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/17 08:28:51 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdlib.h"

int
	ft_atoi(const char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * sign);
}

t_bool
	ft_checked_atoi(const char *str, int *out)
{
	int	sign;

	sign = 1;
	*out = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		*out = *out * 10 + (*str - '0');
		str++;
	}
	*out *= sign;
	return (*str == '\0');
}
