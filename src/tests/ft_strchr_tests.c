#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int c);

static int
	test_single(const char *str, int c)
{
	if (ft_strchr(str, c) != strchr(str, c))
	{
		printf("Failed test_single for ft_strchr. Expected:%lx got:%lx\n", (unsigned long) strchr(str, c), (unsigned long) ft_strchr(str, c));
		return (0);
	}
	return (1);
}

static int
	test_all_chars()
{
	char	buffer[256 * 2];
	int		index;

	index = 0;
	while (index <= 256) {
		buffer[index] = index % 256;
		buffer[index] = -(index % 256);
		index += 2;
	}

	index = -256;
	while (index <= 256)
	{
		if (!test_single(buffer, index))
		{
			printf("At test_all_chars for ft_strchr. Index:%d char:\\%c\n\n", index, index);
			return (0);
		}
		index++;
	}
	return (1);
}

int
	test_strchr()
{
	int	ret;

	ret = 1;
	if (!test_all_chars())
		ret = 0;
	return (ret);
}
