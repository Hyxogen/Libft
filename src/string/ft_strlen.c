/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:09:26 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:09:26 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

size_t
	ft_strlen(const char *str)
{
	const char	*temp;

	temp = str;
	while (*temp)
		temp++;
	return (temp - str);
}
