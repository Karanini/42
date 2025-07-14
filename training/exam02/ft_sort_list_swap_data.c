#include "ft_sort_list.h"

t_list	*ft_sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	swapped;
	int	tmp;
	t_list	*elt;

	swapped = 1;
	elt = lst;
	tmp = lst;
	while (swapped)
	{
		swapped = 0;
		while (elt && elt->next)
		{
			if ((*cmp)(elt->data, elt->next->data) == 0)
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
