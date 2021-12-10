/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 09:53:42 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/10 09:56:21 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int
	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
