/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:53:40 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 09:53:40 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int
	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*arr1;
	const unsigned char	*arr2;

	if (!n || s1 == s2)
		return (0);
	n--;
	arr1 = s1;
	arr2 = s2;
	while (n && *arr1 == *arr2)
	{
		arr1++;
		arr2++;
		n--;
	}
	return (*arr1 - *arr2);
}
