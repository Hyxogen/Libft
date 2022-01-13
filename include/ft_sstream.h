#ifndef FT_SSTREAM_H
# define FT_SSTREAM_H

#ifndef SSTREAM_BUFFER_SIZE
#define SSTREAM_BUFFER_SIZE 1024
#endif

# include <sys/types.h>
# include <ft_stdbool.h>

typedef struct s_sstream {
	char *m_ptr_begin;
	size_t m_write_offset;
	size_t m_buffersize;
} t_sstream;

ft_bool stream_flush(t_sstream *stream, int fd);                          
ft_bool stream_write(t_sstream *stream, const char *str, size_t len);     
ft_bool stream_init(t_sstream *stream, size_t buffersize);

#endif

