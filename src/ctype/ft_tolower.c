/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:49:37 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 09:49:43 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int
	ft_tolower(int c)
{
	if (!ft_isalpha(c) || c >= 'a')
		return (c);
	return (c + ('a' - 'A'));
}
