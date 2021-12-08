/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:53:57 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:07:39 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <ft_string.h>

//Expects that dest and src and len are all not equal to zero
static void
	*ft_memcpy_backward(void *dest, const void *src, size_t len)
{
	char		*dest_arr;
	const char	*src_arr;

	dest_arr = dest + len - 1;
	src_arr = src + len - 1;
	while (len)
	{
		*dest_arr = *src_arr;
		dest_arr--;
		src_arr--;
		len--;
	}
	return (dest);
}

//Expects that dest and src and len are all not equal to zero
static void
	*ft_memcpy_forward(void *dest, const void *src, size_t len)
{
	char		*dest_arr;
	const char	*src_arr;

	dest_arr = dest;
	src_arr = src;
	while (len)
	{
		*dest_arr = *src_arr;
		dest_arr++;
		src_arr++;
		len--;
	}
	return (dest);
}

void
	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dest_arr;
	const char	*src_arr;

	if ((dest == src) || !len)
		return (dest);
	dest_arr = dest;
	src_arr = src;
	if (dest_arr >= src_arr && dest_arr < src_arr + len)
		return (ft_memcpy_backward(dest, src, len));
	else if (dest_arr < src_arr && dest_arr > src_arr - len)
		return (ft_memcpy_forward(dest, src, len));
	return (ft_memcpy(dest, src, len));
}
