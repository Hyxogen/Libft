/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sstream.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 08:24:44 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/17 08:24:44 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sstream.h>

#include <stdlib.h>
#include <unistd.h>
#include <ft_string.h>
#include <ft_stdlib.h>

ft_bool
	_stream_grow(t_sstream *stream, size_t new_size)
{
	stream->m_ptr_begin = ft_realloc(stream->m_ptr_begin,
			stream->m_buffersize, new_size);
	stream->m_buffersize = new_size;
	return (stream->m_ptr_begin == 0);
}

ft_bool
	stream_flush(t_sstream *stream, int fd)
{
	int	ret;

	ret = write(fd, stream->m_ptr_begin, stream->m_write_offset);
	stream->m_write_offset = 0;
	return (ret >= 0);
}

ft_bool
	stream_write(t_sstream *stream, const char *str, size_t len)
{
	if (len + stream->m_write_offset >= stream->m_buffersize)
	{
		_stream_grow(stream, stream->m_buffersize + SSTREAM_BUFFER_SIZE);
		return (stream_write(stream, str, len));
	}
	ft_memcpy(&stream->m_ptr_begin[stream->m_write_offset], str, len);
	stream->m_write_offset += len;
	return (1);
}

ft_bool
	stream_init(t_sstream *stream, size_t buffersize)
{
	stream->m_ptr_begin = malloc(buffersize);
	stream->m_write_offset = 0;
	stream->m_buffersize = buffersize;
	return (1);
}
