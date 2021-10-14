#include "libft.h"

void
	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last)
	{
		if (!last->next)
			break ;
		last = last->next;
	}
	last->next = new;
}
