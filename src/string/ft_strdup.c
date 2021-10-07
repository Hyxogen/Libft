#include <wchar.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t len);

//Test what happens when str is null
char
	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(str) + 1;
	ret = malloc(len);
	ft_memcpy(ret, str, len);
	return (ret);
}
