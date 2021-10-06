char
	*ft_strrchr(const char *str, int c)
{
	char	*ret;

	ret = 0;
	while (1)
	{
		if (*str == (char) c)
			ret = (char*) str;
		if (!*str)
			break ;
		str++;
	}
	return (ret);
}
