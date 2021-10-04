#include <stdio.h>

int	ft_isalpha(char c);

int
	test_isalpha()
{
	int	c;

	c = 0;
	while (c < 265)
	{
		if (ft_isalpha(c) != (c >= 0101 && c <= 0172))
		{
			printf("Failed test ft_isalpha. Expected:%d, got:%d for:%d\n", (c >= 101 && c <= 172), ft_isalpha(c), c);
			return (0);
		}
		c++;
	}
	return (1);
}