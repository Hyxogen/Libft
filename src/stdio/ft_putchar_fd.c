/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:54:34 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:02:21 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t
	ft_putchar_fd(int fd, char c)
{
	return (write(fd, &c, 1));
}
