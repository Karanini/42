

#include "list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elt;

	elt = *lst;
	while (elt)
	{
		elt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = elt;
	}
}
