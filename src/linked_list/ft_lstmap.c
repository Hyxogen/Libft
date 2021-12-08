/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 09:50:14 by dmeijer       #+#    #+#                 */
/*   Updated: 2021/12/08 09:50:15 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

t_list
	*ft_lstmap(t_list *lst, void *(*func)(void *), void (*del)(void *))
{
	t_list		*ret;
	void		*temp_data;
	void		*temp_element;

	ret = 0;
	while (lst)
	{
		temp_data = func(lst->content);
		temp_element = ft_lstnew(temp_data);
		if (!temp_element)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		ft_lstadd_back(&ret, temp_element);
		lst = lst->next;
	}
	return (ret);
}
