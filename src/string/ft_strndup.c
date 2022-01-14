/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 14:13:36 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/10 09:33:31 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>
#include <stdio.h>

char
	*ft_strndup(const char *s1, size_t n)
{
	size_t		len;
	char		*dup;
	const char	*cpy;

	len = 0;
	cpy = s1;
	while (*cpy && n)
	{
		len++;
		cpy++;
		n--;
	}
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, len);
	dup[len] = '\0';
	return (dup);
}
