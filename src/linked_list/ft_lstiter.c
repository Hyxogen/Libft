/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:50:09 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 09:50:10 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

void
	ft_lstiter(t_list *lst, void (*func)(void *))
{
	while (lst)
	{
		func(lst->content);
		lst = lst->next;
	}
}
