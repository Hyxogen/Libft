/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 08:23:56 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/17 08:28:51 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <ft_stdbool.h>
#include <stdlib.h>
#include <ft_stdlib.h>
#include <ft_string.h>
#include <ft_stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#elif (BUFFER_SIZE <= 0)
# error BUFFER_SIZE must not be less than or equal to 0
#endif

t_read_handle
	*start_read(int fd)
{
	t_read_handle	*ret;

	ret = malloc(sizeof(t_read_handle));
	if (ret == NULL)
		return (NULL);
	ret->m_fd = fd;
	ret->m_size = BUFFER_SIZE;
	ret->m_buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (ret->m_buf == NULL)
	{
		free(ret);
		return (NULL);
	}
	ret->m_start = 0;
	ret->m_end = 0;
	return (ret);
}

void
	close_read_handle(t_read_handle *rh)
{
	if (rh)
		free(rh->m_buf);
	free(rh);
}

static t_bool
	push_strn(t_read_handle *rh, const char *str, size_t n)
{
	void	*tmp;

	if ((rh->m_start + n) >= rh->m_size)
	{
		tmp = ft_realloc(rh->m_buf, rh->m_size, rh->m_size + BUFFER_SIZE);
		if (tmp == NULL)
			return (FALSE);
		rh->m_size += BUFFER_SIZE;
		rh->m_buf = tmp;
	}
	ft_memcpy(&rh->m_buf[rh->m_end], str, n);
	rh->m_end += n;
	return (TRUE);
}

/*
It wil override lp
Norminize by shortening names like rh and startoffset and endoffset
Can it go wrong ith read_size when if (tmp) evaluates to true?
*/
ssize_t
	ft_getdelim(char **lp, t_read_handle *rh, int dl)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	read_size;
	char	*tmp;

	while (1)
	{
		tmp = ft_memchr(&rh->m_buf[rh->m_start], dl, rh->m_end - rh->m_start);
		if (tmp)
		{
			read_size = tmp - &rh->m_buf[rh->m_start];
			*lp = ft_strndup(&rh->m_buf[rh->m_start], read_size);
			rh->m_start += (tmp - &rh->m_buf[rh->m_start]) + 1;
			return (read_size);
		}
		read_size = read(rh->m_fd, &buffer[0], BUFFER_SIZE);
		if (read_size < 0)
			return (-1);
		push_strn(rh, &buffer[0], read_size);
		if (read_size == 0)
		{
			tmp = ft_strndup(&rh->m_buf[rh->m_start], rh->m_end - rh->m_start);
			*lp = tmp;
			return (0);
		}
	}
}
