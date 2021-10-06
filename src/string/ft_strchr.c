char
	*ft_strchr(const char *str, int c)
{
	while (1)
	{
		if (*str == (char) c)
			return ((char*) str);
		else if (!*str)
			break;
		str++;
	}
	return (0);
}
