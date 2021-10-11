int	ft_isalpha(int c);

int
	ft_toupper(int c)
{
	if (!ft_isalpha(c) || c <= 'Z')
		return (c);
	return (c - ('a' - 'A'));
}
