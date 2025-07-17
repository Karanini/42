

#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*elt;
	t_list	*previous;

	if (!begin_list || !*begin_list)
		return ;

	elt = *begin_list;
	previous = NULL;
	while (elt)
	{
		if ((*cmp)(elt->data, data_ref) == 0)
		{
			if (!previous)
				*begin_list = *(begin_list)->next;
			else
				previous->next = elt->next;
			tmp = elt;
			elt = elt->next;
			free(tmp);
		}
		else
		{
			previous = elt;
			elt = elt->next;
		}
	}
}

