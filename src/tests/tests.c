#include <stdio.h>

int	test_memset();
int	test_isalpha();
int	test_ftstrlen();
int test_isalnum();
int	test_isdigit();
int	test_isascii();
int	test_isprint();
int	test_bzero();
int	test_memcpy();
int	test_memmove();
int	test_strlcat();
int	test_strlcpy();
int	test_toupper();
int	test_tolower();
int	test_strchr();

//TODO fill in UINT_MAX in places that accept numbers
int
	main()
{
	if (!test_isalpha())
		printf("Test for ft_isalpha failed!\n");
	else
		printf("Passed tests for ft_isalpha!\n");
	if (!test_isdigit())
		printf("Test for ft_isdigit failed!\n");
	else
		printf("Passed tests for ft_isdigit!\n");	
	if (!test_isalnum())
		printf("Test for ft_isalnum failed!\n");
	else
		printf("Passed tests for ft_isalnum!\n");	
	if (!test_isprint())
		printf("Test for ft_isprint failed!\n");
	else
		printf("Passed tests for ft_isprint!\n");
	if (!test_isascii())
		printf("Test for ft_isascii failed!\n");
	else
		printf("Passed tests for ft_isascii!\n");	
	if (!test_memset())
		printf("Test for ft_memset failed!\n");
	else
		printf("Passed tests for ft_memset!\n");
	if (!test_ftstrlen())
		printf("Test for ft_strlen failed!\n");
	else
		printf("Passed tests for ft_strlen!\n");
	if (!test_bzero())
		printf("Test for ft_bzero failed!\n");
	else
		printf("Passed tests for ft_bzero!\n");	
	if (!test_memcpy())
		printf("Test for ft_memcpy failed!\n");
	else
		printf("Passed tests for ft_memcpy!\n");	
	if (!test_memmove())
		printf("Test for ft_memmove failed!\n");
	else
		printf("Passed tests for ft_memmove!\n");
	if (!test_strlcat())
		printf("Test for ft_strlcat failed!\n");
	else
		printf("Passed tests for ft_strlcat!\n");	
	if (!test_strlcpy())
		printf("Test for ft_strlcpy failed!\n");
	else
		printf("Passed tests for ft_strlcpy!\n");
	if (!test_toupper())
		printf("Test for ft_toupper failed!\n");
	else
		printf("Passed tests for ft_toupper!\n");
	if (!test_tolower())
		printf("Test for ft_tolower failed!\n");
	else
		printf("Passed tests for ft_tolower!\n");
	if (!test_strchr())
		printf("Test for ft_strchr failed!\n");
	else
		printf("Passed tests for ft_strchr!\n");
	return (0);
}