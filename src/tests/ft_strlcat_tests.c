#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize);

static int
	test_strings_fit()
{
	int		first;
	int		second;
	size_t	retc;
	size_t	rett;
	char	*strs_o[] = {
		"Hallo dit is een string",
		"Hallo",
		" string",
		" ",
		"\n",
		"",
		0
	};
	char	 *strs_s[] = {
		"Lorem ipsum dolor sit amet, consectetur.",
		"non, placerat porttitor velit. ",
		"consequat ac egestas vel, molestie et turpis. Aliquam",
		"\n",
		" ",
		"",
		0
	};
	char	cbuffer[1024];
	char	tbuffer[1024];
	first = 0;
	while (strs_o[first])
	{
		second = 0;
		while (strs_s[second])
		{
			memset(cbuffer, 0, 1024);
			memset(tbuffer, 0, 1024);
			memcpy(cbuffer, strs_o[first], strlen(strs_o[first]));
			memcpy(tbuffer, strs_o[first], strlen(strs_o[first]));
			
			rett = ft_strlcat(tbuffer, strs_s[second], strlen(strs_o[first]) + strlen(strs_s[second]) + 1);
			retc = strlcat(cbuffer, strs_s[second], strlen(strs_o[first]) + strlen(strs_s[second]) + 1);
			if (memcmp(tbuffer, cbuffer, 1024))
			{
				printf("Failed test_strings_fit. Expected 0, got: %d at first:%s(%d) second:%s(%d)\n", memcmp(tbuffer, cbuffer, 1024), strs_o[first], first, strs_s[second], second);
				printf("Correct:\n%s\n", cbuffer);
				printf("Test:\n%s\n", tbuffer);
				return (0);
			}
			if (rett != retc)
			{
				printf("Failed test_strings_fit. Expected return:%zu, got: %zu at first:%s(%d) second:%s(%d)\n", retc, rett, strs_o[first], first, strs_s[second], second);
				return (0);
			}
			second++;
		}
		first++;
	}
	return (1);
}

static int
	test_strings_no_fit()
{
	int		first;
	int		second;
	size_t	retc;
	size_t	rett;
	size_t	flen;
	size_t	slen;
	char	*strs_o[] = {
		"Hallo dit is een string",
		"Hallo",
		" string",
		" ",
		"\n",
		"",
		0
	};
	char	 *strs_s[] = {
		"Lorem ipsum dolor sit amet, consectetur.",
		"non, placerat porttitor velit. ",
		"consequat ac egestas vel, molestie et turpis. Aliquam",
		"\n",
		" ",
		"",
		0
	};
	char	cbuffer[1024];
	char	tbuffer[1024];
	first = 0;
	while (strs_o[first])
	{
		second = 0;
		while (strs_s[second])
		{
			flen = strlen(strs_o[first]);
			slen = strlen(strs_s[second]);
			while (slen)
			{
				memset(cbuffer, 0, 1024);
				memset(tbuffer, 0, 1024);
				memcpy(cbuffer, strs_o[first], flen);
				memcpy(tbuffer, strs_o[first], flen);

				rett = ft_strlcat(tbuffer, strs_s[second], flen + slen + 1);
				retc = strlcat(cbuffer, strs_s[second], flen + slen + 1);
				if (memcmp(tbuffer, cbuffer, 1024))
				{
					printf("Failed test_strings_no_fit. Expected 0, got: %d at first:%d second:%d offset:%lu\n", memcmp(tbuffer, cbuffer, 1024), first, second, strlen(strs_s[second]) - slen);
					printf("Correct:\n%s\n", cbuffer);
					printf("Test:\n%s\n", tbuffer);
					return (0);
				}
				if (rett != retc)
				{
					printf("Failed test_strings_no_fit. Expected return:%zu, got: %zu at first:%d second:%d offset:%lu\n", retc, rett, first, second, strlen(strs_s[second]) - slen);
					return (0);
				}
				slen--;
			}
			second++;
		}
		first++;
	}
	return (1);
}

int
	test_strlcat()
{
	int	ret;

	ret = 1;
	if (!test_strings_fit())
		ret = 0;
	if (!test_strings_no_fit())
		ret = 0;
	return (ret);
}