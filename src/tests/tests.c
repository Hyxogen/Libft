#include <stdio.h>

int	test_memset();
int	test_isalpha();
int	test_ftstrlen();
int test_isalnum();

int
	main()
{
	if (!test_isalpha())
		printf("Test for ft_isalpha failed!\n");
	else
		printf("Passed tests for ft_isalpha!\n");
	if (!test_memset())
		printf("Test for ft_memset failed!\n");
	else
		printf("Passed tests for ft_memset!\n");	
	if (!test_ftstrlen())
		printf("Test for ft_strlen failed!\n");
	else
		printf("Passed tests for ft_strlen!\n");	
	if (!test_isalnum())
		printf("Test for ft_isalnum failed!\n");
	else
		printf("Passed tests for ft_isalnum!\n");	
	
	return (0);
}