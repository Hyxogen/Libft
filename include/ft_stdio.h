/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stdio.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:57:21 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:04:40 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <wchar.h>

size_t	ft_putchar_fd(int fd, char c);
size_t	ft_putstr_fd(int fd, char *str);
size_t	ft_putendl_fd(int fd, char *str);
size_t	ft_putnbr_fd(int fd, int n);
size_t	put_nbr_base_signed(int fd, long long number,
	 const char *baseStr, int base);
size_t	put_nbr_base_unsigned(int fd, unsigned long long number,
	 const char *baseStr, int base);
#endif