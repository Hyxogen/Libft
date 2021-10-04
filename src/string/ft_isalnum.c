int	ft_isalpha(char c);
int	ft_isdigit(char c);

int
	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
