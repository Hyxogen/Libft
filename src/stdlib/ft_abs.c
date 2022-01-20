/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 08:24:47 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 10:42:20 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int
	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

long
	ft_labs(long val)
{
	if (val < 0)
		return (-val);
	return (val);
}
