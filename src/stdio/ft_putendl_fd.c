/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:57:28 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 12:07:14 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_stdio.h>

size_t
	ft_putendl_fd(int fd, const char *str)
{
	return (ft_putstr_fd(fd, str) + ft_putchar_fd(fd, '\n'));
}
