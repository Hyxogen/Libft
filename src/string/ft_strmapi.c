/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:09:29 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:09:35 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char
	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	unsigned int	index;
	char			*copy;
	char			*ret;

	copy = ft_strdup(str);
	if (!copy)
		return (0);
	ret = copy;
	index = 0;
	while (*copy)
	{
		*copy = func(index, *copy);
		index++;
		copy++;
	}
	return (ret);
}
