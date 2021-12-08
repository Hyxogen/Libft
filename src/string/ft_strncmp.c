/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:09:38 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:09:39 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int
	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	n--;
	while (*s1 && *s1 == *s2 && n)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
