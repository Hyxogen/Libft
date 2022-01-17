/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_math.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 08:26:31 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/17 08:26:46 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <sys/types.h>

int		ft_min(int a, int b);
long	ft_lmin(long a, long b);
size_t	ft_stmin(size_t a, size_t b);

long	ft_lmax(long a, long b);
size_t	ft_stmax(size_t a, size_t b);

#endif
