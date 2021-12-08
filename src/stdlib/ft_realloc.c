/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 14:03:18 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 14:08:02 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>

void
	*ft_realloc(void *ptr, size_t oldSize, size_t newSize)
{
	unsigned char	*ret;

	ret = malloc(newSize);
	if (!ret)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(ret, ptr, oldSize);
		free(ptr);
	}
	return (ret);
}
