#include <string.h>
#include <stdio.h>

void	*ft_memset(void *dest, int ch, size_t len);

static int
	test_nulldest()
{
	char	*ctemp;
	char	*ttemp;
	
	ctemp = memset(0, 0, 0);
	ttemp = ft_memset(0, 0, 0);
	return (1);
}

static int
	test_fill_zero_s()
{
	char ctemp[100];
	char ttemp[100];
	int index;

	index = 0;
	while (index < 100)
	{
		memset(ctemp, 0, index);
		ft_memset(ttemp, 0, index);
		if (memcmp(ctemp, ttemp, index))
		{
			printf("Failed test_fill_zero_s. Expected: 1, got: 0 at index:%d\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

int
	test_memset()
{
	int ret;

	ret = 1;
	if (!test_nulldest())
	{
		printf("Failed test_nulldest for memset. Did you handle your edge cases?\n");
		ret = 0;
	}
	if (!test_fill_zero_s())
		ret = 0;
	return (ret);
}