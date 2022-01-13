#ifndef FT_SSTREAM_H
# define FT_SSTREAM_H

#ifndef SSTREAM_BUFFER_SIZE
#define SSTREAM_BUFFER_SIZE 1024
#endif

# include <sys/types.h>

typedef struct s_sstream {
	char *m_ptr_begin;
	size_t m_write_offset;
	size_t m_buffersize;
} t_sstream;

#endif

