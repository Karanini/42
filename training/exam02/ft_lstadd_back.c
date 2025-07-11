
#include "list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elt;

	elt = ft_lstlast(*lst);
	if (!elt)
	{
		*lst = new;
		return ;
	}
	elt->next = new;
}
