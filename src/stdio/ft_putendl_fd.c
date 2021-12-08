/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:57:28 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:03:19 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_stdio.h>

void
	ft_putendl_fd(int fd, const char *str)
{
	return (ft_putstr_fd(fd, str) + ft_putchar_fd(fd, '\n'));
}
