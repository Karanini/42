

#include "list.h"
#include <string.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	 t_list	*elt;
	 t_list	*elt2;

	 if (!cmp)
		 return ;
	 elt = *begin_list;
	 while (elt)
	 {
		elt2 = elt->next;
		if (!(*cmp)(elt->content, data_ref))
			 free(elt);
		elt = elt2;
	 }
}

int	main(void)
{
	t_list	*elt1 = ft_lstnew("1");
	t_list	*elt2 = ft_lstnew("32");
	ft_lstadd_front(&elt1, elt2);
	t_list	*elt3 = ft_lstnew("w32h");
	ft_lstadd_front(&elt2, elt3);
	print_list(elt3);
	ft_list_remove_if(&elt3, (char *)"32", &strcmp);
	print_list(elt3);
	return (0);
}
