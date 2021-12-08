#include <wchar.h>
#include <ft_stdbool.h>
#include <stdlib.h>
#include <ft_stdlib.h>
#include <ft_string.h>
#include <ft_stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

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
	ret->m_Needle = ret->m_Buffer;
	return (ret);
}

void close_read_handle(t_read_handle *handle)
{
	free(handle);
}

static ft_bool push_strn(t_read_handle *handle, const char *str, size_t n)
{
	void	*temp;

	if ((handle->m_Needle + n) >= (handle->m_Buffer + handle->m_Size))
	{
		temp = ft_realloc(handle->m_Buffer, handle->m_Size, handle->m_Size + BUFFER_SIZE);
		if (!temp)
			return (FALSE);
		handle->m_Buffer = temp;
		handle->m_Needle = handle->m_Buffer + handle->m_Size;
		handle->m_Size += BUFFER_SIZE;
	}
	ft_memcpy(handle->m_Needle, str, n);
	handle->m_Needle += n;
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
		temp = ft_memchr(&buffer[0], (char)delim, read_size);
		if (temp)
		{
			handle->m_Needle -= BUFFER_SIZE - read_size;
			*linep = ft_strndup(handle->m_Buffer, (handle->m_Needle - handle->m_Buffer) - 1);
			printf("found str:%s, actual(%zu):%.*s\n", *linep, (handle->m_Needle - handle->m_Buffer - 1), (int) (handle->m_Needle - handle->m_Buffer) - 1, handle->m_Buffer);
			return (handle->m_Needle - handle->m_Buffer);
		}
		if (read_size == 0)
		{
			*linep = ft_strndup(handle->m_Buffer, handle->m_Needle - handle->m_Buffer);
			return (0);
		}
	}
}
