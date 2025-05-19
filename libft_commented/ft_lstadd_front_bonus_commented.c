
#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = *lst;
	//if *lst is NULL we just have to define new
	//as the first element of the list
	*lst = new;
}
