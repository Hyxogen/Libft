/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsep.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:10:00 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:10:05 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char
	*ft_strsep(char **stringp, const char *delim)
{
	char	*copy;
	char	*delim_pos;

	copy = *stringp;
	delim_pos = ft_strchrset(*stringp, delim);
	if (delim_pos)
	{
		*delim_pos = '\0';
		*stringp = delim_pos + 1;
	}
	else
		*stringp = 0;
	return (copy);
}
