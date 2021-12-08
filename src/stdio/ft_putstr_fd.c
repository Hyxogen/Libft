/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:57:15 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:02:58 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_string.h>

size_t
	ft_putstr_fd(int fd, const char *str)
{
	return (write(fd, str, ft_strlen(str)));
}
