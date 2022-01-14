/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stdlib.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:50:34 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 14:07:57 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <wchar.h>
# include "ft_stdbool.h"

ft_bool		ft_checked_atoi(const char *str, int* out);
int		ft_atoi(const char *str);
void	*ft_realloc(void *ptr, size_t oldSize, size_t newSize);
long	ft_labs(long val);
#endif
