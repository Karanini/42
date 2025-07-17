

#include "ft_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	swapped;
	t_list	*elt;

	if (!lst)
		return (NULL);
	swapped = 1;
	elt = lst;
	while (swapped)
	{
		swapped = 0;
		while (elt && elt->next)
		{
			if((*cmp)(elt->data, elt->next->data) == 0)
			{
				tmp = elt->data;
				elt->data = elt->next->data;
				elt->next->data = tmp;
				swapped = 1;
			}
			elt = elt->next;
		}
		elt = lst;
	}
	return (lst);
}
