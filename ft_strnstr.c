#include <wchar.h>

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*needle_start;

	if (!*needle)
		return ((char *) haystack);
	needle_start = needle;
	while (len)
	{
		if (*haystack != *needle)
			needle = needle_start;
		if (*haystack == *needle && !*(needle + 1))
			return ((char *) haystack - (needle - needle_start));
		else if (*haystack == *needle)
			needle++;
		if (!*haystack)
			break ;
		haystack++;
		len--;
	}
	return (0);
}
