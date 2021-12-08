/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 10:08:34 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 10:08:43 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void
	ft_striteri(char *str, void (*func)(unsigned int, char*))
{
	int	index;

	index = 0;
	while (*str)
	{
		func(index, str);
		index++;
		str++;
	}
}
