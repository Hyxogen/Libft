/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:53:36 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 09:53:36 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

void
	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*arr;

	arr = (unsigned char *) s;
	while (n)
	{
		if (*arr == (unsigned char) c)
			return (arr);
		arr++;
		n--;
	}
	return (0);
}
