/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:50:12 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 09:50:12 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

t_list
	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}
