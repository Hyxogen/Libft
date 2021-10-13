#include <stdint.h>
#include <wchar.h>

static void
	*ft_memset_eightb(void *dest, int ch, size_t len)
{
	uint64_t	*array;
	uint64_t val;

	val = 0;
	val = (uint8_t) ch;
	val |= ((uint8_t) ch) << 8;
	val |= val << 16;
	val |= val << 32;
	while (len)
	{
		*array = val;
		len -= 8;
		array++;
	}
	return (dest);
}

static void
	*ft_memset_fourb(void *dest, int ch, size_t len)
{
	uint32_t	*array;
	uint32_t val;

	val = 0;
	val = (uint8_t) ch;
	val |= ((uint8_t) ch) << 8;
	val |= val << 16;
	while (len)
	{
		*array = val;
		len -= 4;
		array++;
	}
	return (dest);
}


static void
	*ft_memset_twob(void *dest, int ch, size_t len)
{
	uint16_t	*array;
	uint16_t val;

	val = 0;
	val = (uint8_t) ch;
	val |= ((uint8_t) ch) << 8;
	while (len)
	{
		*array = val;
		len -= 2;
		array++;
	}
	return (dest);
}

void
	*ft_memset_singleb(void *dest, int ch, size_t len)
{
	unsigned char	*array;

	if (!len)
		return (dest);
	array = dest;
	while (len)
	{
		*array = (unsigned char) ch;
		len--;
		array++;
	}
	return (dest);
}

void
	*ft_memset(void *dest, int ch, size_t len)
{
	unsigned char	*array;

	if (!len)
		return (dest);
	array = dest;
	while (len)
	{
		*array = (unsigned char) ch;
		len--;
		array++;
	}
	return (dest);
}
