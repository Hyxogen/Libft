/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stdio.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:57:21 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/10 08:47:39 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <wchar.h>

typedef struct s_read_handle {
	int		m_fd;
	size_t	m_size;
	size_t	m_start;
	size_t	m_end;
	char	*m_buf;
}	t_read_handle;

/*TODO change long long to int64*/
size_t			ft_putchar_fd(int fd, char c);
size_t			ft_putstr_fd(int fd, const char *str);
size_t			ft_putendl_fd(int fd, const char *str);
size_t			ft_putnbr_fd(int fd, int n);
size_t			put_nbr_base_signed(int fd, long number,
	 const char *baseStr, int base);
size_t			put_nbr_base_unsigned(int fd, unsigned long number,
	 const char *baseStr, int base);
ssize_t			ft_getdelim(char **linep, t_read_handle *handle, int delim);
t_read_handle	*start_read(int fd);
void			close_read_handle(t_read_handle *handle);
#endif
