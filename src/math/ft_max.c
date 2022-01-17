/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 08:23:59 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/17 08:24:00 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>

long
	ft_lmax(long a, long b)
{
	if (a >= b)
		return (a);
	return (b);
}

size_t
	ft_stmax(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}
