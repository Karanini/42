


#include "ft_sort_list.h"
#include <stdio.h>

int	comp(int a, int b)
{
	if (a > b)
		return (0);  // Return 0 when swap is needed
	return (1);      // Return non-zero when no swap needed
}

t_list	*ft_sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*elt;
	t_list	*tmp;
	t_list	*previous;
	int		not_begin;
	int		swapped;

	if (!lst || !lst->next)
		return (lst);

	swapped = 1;
	while (swapped)  // Multiple passes until no swaps needed
	{
		swapped = 0;
		elt = lst;
		previous = NULL;  // Start with NULL since there's no node before head
		not_begin = 0;

		while (elt && elt->next)  // Check elt->next exists before accessing it
		{
			if ((*cmp)(elt->data, elt->next->data) == 0)  // Your logic: 0 means swap
			{
				tmp = elt->next;
				elt->next = elt->next->next;
				tmp->next = elt;

				if (not_begin == 1)
					previous->next = tmp;
				else  // not_begin == 0, we're swapping at head
					lst = tmp;

				previous = tmp;  // After swap, tmp is now before elt
				swapped = 1;
			}
			else
			{
				previous = elt;
				elt = elt->next;
			}
			not_begin = 1;
		}
	}
	return (lst);
}






