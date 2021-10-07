#include <stdio.h>
#include "../../include/libft.h"
#include <string.h>

typedef struct s_test {
	char			*m_test_str;
	char			*m_corr_str;
	unsigned int	m_start;
	size_t			m_len;
}					t_test;

const static t_test g_pairs[] = {
	{"Hallo, dit is een string!", "dit is een string!", 7, 19},
	{0, 0, 0, 0}
};

static int
	test_single(const t_test *test)
{
	char	*tret;

	tret = ft_substr(test->m_test_str, test->m_start, test->m_len);
	if (strcmp(tret, test->m_corr_str))
	{
		printf("Failed test_single.\nExpected:\n%s\ngot:\n%s\nm_start:%u m_len:%zu\n", test->m_corr_str, tret, test->m_start, test->m_len);
		return (0);
	}
	return (1);
}

static int
	test_all()
{
	int	index;

	index = 0;
	while (g_pairs[index].m_test_str)
	{
		if (!test_single(&g_pairs[index]))
		{
			printf("At test_all. index%d\n\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

int
	test_substr()
{
	int	ret;

	ret = 1;
	if (!test_all())
		ret = 0;
	return (ret);
}