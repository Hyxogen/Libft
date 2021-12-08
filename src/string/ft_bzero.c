/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:51:19 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:07:04 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void
	ft_bzero(void *dest, size_t len)
{
	ft_memset(dest, 0, len);
}
