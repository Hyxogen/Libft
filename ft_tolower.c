int	ft_isalpha(int c);

int
	ft_tolower(int c)
{
	if (!ft_isalpha(c) || c >= 'a')
		return (c);
	return (c + ('a' - 'A'));
}
