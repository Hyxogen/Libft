#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//These tests arent really good, since they don't check if strlcat might cause segfaults. Todo add tests with really big strings (like really big) to test for segfaults

const static char 	*test_dsts[] = {
	"Hallo dit is een string",
	"Hallo",
	" string",
	" ",
	"\n",
	"",
	0
};

const static char	*test_srcs[] = {
	"Lorem ipsum dolor sit amet, consectetur.",
	"non, placerat porttitor velit. ",
	"consequat ac egestas vel, molestie et turpis. Aliquam",
	"\n",
	" ",
	"",
	0
};

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize);

// static int
// 	test_strings_no_fit()
// {
// 	int		first;
// 	int		second;
// 	size_t	retc;
// 	size_t	rett;
// 	size_t	flen;
// 	size_t	slen;
// 	char	*strs_o[] = {
// 		"Hallo dit is een string",
// 		"Hallo",
// 		" string",
// 		" ",
// 		"\n",
// 		"",
// 		0
// 	};
// 	char	 *strs_s[] = {
// 		"Lorem ipsum dolor sit amet, consectetur.",
// 		"non, placerat porttitor velit. ",
// 		"consequat ac egestas vel, molestie et turpis. Aliquam",
// 		"\n",
// 		" ",
// 		"",
// 		0
// 	};
// 	char	cbuffer[1024];
// 	char	tbuffer[1024];
// 	first = 0;
// 	while (strs_o[first])
// 	{
// 		second = 0;
// 		while (strs_s[second])
// 		{
// 			flen = strlen(strs_o[first]);
// 			slen = strlen(strs_s[second]);
// 			while (slen)
// 			{
// 				memset(cbuffer, 0, 1024);
// 				memset(tbuffer, 0, 1024);
// 				memcpy(cbuffer, strs_o[first], flen);
// 				memcpy(tbuffer, strs_o[first], flen);

// 				rett = ft_strlcat(tbuffer, strs_s[second], flen + slen);
// 				retc = strlcat(cbuffer, strs_s[second], flen + slen);
// 				if (memcmp(tbuffer, cbuffer, 1024))
// 				{
// 					printf("Failed test_strings_no_fit. Expected 0, got: %d at first:%d second:%d offset:%lu\n", memcmp(tbuffer, cbuffer, 1024), first, second, strlen(strs_s[second]) - slen);
// 					printf("Correct:\n%s\n", cbuffer);
// 					printf("Test:\n%s\n", tbuffer);
// 					return (0);
// 				}
// 				if (rett != retc)
// 				{
// 					printf("Failed test_strings_no_fit. Expected return:%zu got: %zu at first:%d second:%d offset:%lu\n", retc, rett, first, second, strlen(strs_s[second]) - slen);
// 					return (0);
// 				}
// 				slen--;
// 			}
// 			second++;
// 		}
// 		first++;
// 	}
// 	return (1);
// }

static int
	test_single(const char *tdst, const char *tsrc, size_t tsize)
{
	char	test_dst[200];
	char	corr_dst[200];
	size_t	tret;
	size_t	cret;
	size_t	tdst_size;

	tdst_size = strlen(tdst);
	memset(test_dst, 0, tsize);
	memset(corr_dst, 0, tsize);
	memcpy(test_dst, tdst, tdst_size);
	memcpy(corr_dst, tdst, tdst_size);

	cret = strlcat(corr_dst, tsrc, tsize);
	tret = ft_strlcat(test_dst, tsrc, tsize);
	if (tret != cret)
	{
		printf("Failed test_single for ft_strlcat! Expected return:%zu got:%zu\n", cret, tret);
		return (0);
	}
	if (memcmp(test_dst, corr_dst, tsize))
	{
		printf("Failed test_single for ft_strlcat! Expected:\n%s\ngot:%s\n", corr_dst, test_dst);
		return (0);
	}
	return (1);
}

static int
	test_insufficient()
{
	size_t	dst_index;
	size_t	src_index;
	size_t	dstlen;
	size_t	index;

	dst_index = 0;
	while (test_dsts[dst_index])
	{
		dstlen = strlen(test_dsts[dst_index]);
		src_index = 0;
		while (test_srcs[src_index])
		{
			index = 0;
			while (index <= dstlen)
			{
				if (!test_single(test_dsts[dst_index], test_srcs[src_index], index))
				{
					printf("At test_insufficient for ft_strlcat, dst_index:%zu src_index:%zu index:%zu\n", dst_index, src_index, index);
					return (0);
				}
				index++;
			}
			src_index++;
		}
		dst_index++;
	}
	return (1);
}

static int
	test_strings_fit()
{
	size_t	dst_index;
	size_t	src_index;
	size_t	dstlen;
	size_t	srclen;

	dst_index = 0;
	while (test_dsts[dst_index])
	{
		dstlen = strlen(test_dsts[dst_index]);
		src_index = 0;
		while (test_srcs[src_index])
		{
			srclen = strlen(test_srcs[src_index]);
			if (!test_single(test_dsts[dst_index], test_srcs[src_index], dstlen + srclen + 1))
			{
				printf("At test_strings_fit for ft_strlcat, dst_index:%zu src_index:%zu\n", dst_index, src_index);
				return (0);
			}
			src_index++;
		}
		dst_index++;
	}
	return (1);
}

static int
	test_strings_no_fit()
{
	size_t	dst_index;
	size_t	src_index;
	size_t	dstlen;
	size_t	srclen;
	size_t	index;

	dst_index = 0;
	while (test_dsts[dst_index])
	{
		dstlen = strlen(test_dsts[dst_index]);
		src_index = 0;
		while (test_srcs[src_index])
		{
			srclen = strlen(test_srcs[src_index]);
			index = 0;
			while (index <= (srclen + 1))
			{
				if (!test_single(test_dsts[dst_index], test_srcs[src_index], dstlen + index))
				{
					printf("At test_strings_no_fit for ft_strlcat, dst_index:%zu src_index:%zu index:%zu\n", dst_index, src_index, index);
					return (0);
				}
				index++;
			}
			src_index++;
		}
		dst_index++;
	}
	return (1);
}

int
	test_strlcat()
{
	int	ret;

	ret = 1;
	if (!test_insufficient())
		ret = 0;
	if (!test_strings_fit())
		ret = 0;
	if (!test_strings_no_fit())
		ret = 0;
	return (ret);
}