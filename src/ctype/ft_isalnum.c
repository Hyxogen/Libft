/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:49:13 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 09:49:14 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int
	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
