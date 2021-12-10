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
#define BUFFER_SIZE 1024
#else
#if (BUFFER_SIZE <= 0)
#error BUFFER_SIZE must not be less than or equal to 0
#endif
#endif

t_read_handle	*start_read(int fd)
{
	t_read_handle	*ret;

	ret = malloc(sizeof(t_read_handle));
	if (ret == NULL)
		return (NULL);
	ret->m_FD = fd;
	ret->m_Size = BUFFER_SIZE;
	ret->m_Buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (ret->m_Buffer == NULL)
	{
		free(ret);
		return (NULL);
	}
	ret->m_StartOffset = 0;
	ret->m_EndOffset = 0;
	return (ret);
}

void close_read_handle(t_read_handle *handle)
{
	free(handle);
}

static ft_bool push_strn(t_read_handle *handle, const char *str, size_t n)
{
	void	*temp;

	if ((handle->m_StartOffset + n) >= handle->m_Size)
	{
		temp = ft_realloc(handle->m_Buffer, handle->m_Size, handle->m_Size + BUFFER_SIZE);
		if (temp == NULL)
			return (FALSE);
		handle->m_Size += BUFFER_SIZE;
	}
	ft_memcpy(&handle->m_Buffer[handle->m_EndOffset], str, n);
	handle->m_EndOffset += n;
	return (TRUE);
}

/*
It wil override linep
*/
ssize_t ft_getdelim(char **linep, t_read_handle *handle, int delim)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	read_size;
	char	*temp;

	while (1)
	{
		read_size = read(handle->m_FD, &buffer[0], BUFFER_SIZE);
		if (read_size < 0)
			return (-1);
		push_strn(handle, &buffer[0], read_size);
		temp = ft_memchr(&handle->m_Buffer[handle->m_EndOffset - read_size], (char) delim, read_size);
		if (temp)
		{
			temp = ft_strndup(&handle->m_Buffer[handle->m_StartOffset], temp - &handle->m_Buffer[handle->m_StartOffset]);
			*linep = temp;
			handle->m_StartOffset = handle->m_EndOffset;
			return (read_size);
		}
		else if (read_size == 0)
		{
			temp = ft_strndup(&handle->m_Buffer[handle->m_StartOffset], temp - &handle->m_Buffer[handle->m_StartOffset]);
			*linep = temp;
			return (0);
		}
	}
}
