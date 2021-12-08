/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:49:25 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 09:49:25 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int
	ft_isprint(int c)
{
	return (c >= 040 && c <= 0176);
}
