/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:10:48 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:12:16 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>

char
	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;

	while (start && *str)
	{
		str++;
		start--;
	}
	ret = malloc(len + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, str, len + 1);
	return (ret);
}
