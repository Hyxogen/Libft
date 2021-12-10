/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:08:30 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/10 09:04:26 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include <ft_string.h>

char
	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(str) + 1;
	ret = malloc(len);
	if (!ret)
		return (0);
	ft_memcpy(ret, str, len);
	return (ret);
}
