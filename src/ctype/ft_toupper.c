/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:49:50 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 09:49:50 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int
	ft_toupper(int c)
{
	if (!ft_isalpha(c) || c <= 'Z')
		return (c);
	return (c - ('a' - 'A'));
}
