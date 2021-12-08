/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:07:51 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:07:52 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char
	*ft_strchr(const char *str, int c)
{
	while (1)
	{
		if (*str == (char) c)
			return ((char *) str);
		else if (!*str)
			break ;
		str++;
	}
	return (0);
}

char
	*ft_strchrset(const char *str, const char *charset)
{
	char	*closest_pos;
	char	*char_pos;

	closest_pos = 0;
	while (*charset)
	{
		char_pos = ft_strchr(str, *charset);
		if (char_pos && (!closest_pos || char_pos < closest_pos))
			closest_pos = char_pos;
		charset++;
	}
	return (closest_pos);
}
